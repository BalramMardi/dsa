#include <iostream>
#include <vector>

using namespace std;

int find(int id, vector<int> &parent)
{
    if (parent[id] == id)
    {
        return id;
    }
    else
    {
        parent[id] = find(parent[id], parent);
        return parent[id];
    }
}

vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
{
    vector<int> res;
    if (m <= 0 || n <= 0)
    {
        return res;
    }

    int count = 0;
    vector<int> parent(m * n, -1);
    vector<int> rank(m * n, 0);
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (const auto &p : positions)
    {
        int cellno = p[0] * n + p[1];
        parent[cellno] = cellno;
        rank[cellno]++;
        count++;

        for (const auto &dir : directions)
        {
            int x = p[0] + dir[0], y = p[1] + dir[1];
            int neighbor = x * n + y;

            if (x < 0 || x >= m || y < 0 || y >= n || parent[neighbor] == -1)
            {
                continue;
            }
            int neighborRoot = find(neighbor, parent);
            int cellnoRoot = find(cellno, parent);
            if (cellnoRoot != neighborRoot)
            {

                if (rank[cellnoRoot] >= rank[neighborRoot])
                {
                    rank[cellnoRoot] += rank[neighborRoot];
                    parent[neighborRoot] = cellnoRoot;
                }
                else
                {
                    rank[neighborRoot] += rank[cellnoRoot];
                    parent[cellnoRoot] = neighborRoot;
                }
                count--;
            }
        }

        res.push_back(count);
    }

        return res;
}

int main()
{
    int m, n, q;
    cin >> m >> n >> q;
    vector<vector<int>> positions(q, vector<int>(2));
    for (int i = 0; i < q; i++)
    {
        cin >> positions[i][0] >> positions[i][1];
    }

    vector<int> result = numIslands2(m, n, positions);

    for (int val : result)
    {
        cout << val << endl;
    }

    return 0;
}
