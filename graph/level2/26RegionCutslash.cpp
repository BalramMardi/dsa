#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int> &parent)
{
    if (parent[x] != x)
    {

        parent[x] = find(parent[x], parent);
    }

    return parent[x];
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank, int &count)
{

    int xset = find(x, parent);
    int yset = find(y, parent);

    if (xset != yset)
    {
        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }

        else
        {
            parent[xset] = yset;
            rank[yset] = rank[yset] + 1;
        }
    }
    else
    {
        count++;
    }
}

int regionsBySlashes(vector<string> &grid)
{
    int n = grid.size();
    int dots = n + 1;
    vector<int> parent(dots * dots);
    vector<int> rank(dots * dots, 1);
    int count = 1;

    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < dots; i++)
    {
        for (int j = 0; j < dots; j++)
        {
            if (i == 0 or j == 0 or i == dots - 1 or j == dots - 1)
            {
                int cellno = i * dots + j;
                if (cellno != 0)
                {
                    Union(0, cellno, parent, rank, count);
                }
            }
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {
        string &ch = grid[i];
        for (int j = 0; j < ch.length(); j++)
        {
            if (ch[j] == '/')
            {
                int cellno1 = i * dots + (j + 1);
                int cellno2 = (i + 1) * dots + (j);
                Union(cellno1, cellno2, parent, rank, count);
            }

            else if (ch[j] == '\\')
            {
                int cellno1 = i * dots + (j);
                int cellno2 = (i + 1) * dots + (j + 1);
                Union(cellno1, cellno2, parent, rank, count);
            }
        }
    }

    return count;
}

int main()
{
    // Example usage
    vector<string> grid = {"/\\", "\\/"};
    cout << "Number of regions: " << regionsBySlashes(grid) << endl;

    return 0;
}
