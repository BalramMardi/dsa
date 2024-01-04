#include <iostream>
#include <vector>
using namespace std;

int time = 0;

void AP_Bridges(vector<vector<int>> &graph, int *disc, int *low, int *parent,
                bool *Apoint, bool *visited, int src)
{
    disc[src] = low[src] = ++time;
    int counter = 0;
    visited[src] = true;
    for (int e = 0; e < graph[src].size(); e++)
    {
        int nbr = graph[src][e];
        if (parent[src] == nbr)
        {
            continue;
        }
        else if (visited[nbr] == true)
        {
            low[src] = min(low[src], disc[nbr]);
        }
        else
        {
            parent[nbr] = src;
            AP_Bridges(graph, disc, low, parent, Apoint, visited, nbr);
            low[src] = min(low[src], low[nbr]);
            if (parent[src] == -1)
            {
                counter++;
                if (counter >= 2)
                {
                    Apoint[src] = true;
                }
            }
            else
            {
                if (low[nbr] >= disc[src])
                {
                    Apoint[src] = true;
                }
            }
        }
    }
}

void DFS(vector<vector<int>> &graph, int v, bool *visited, int &count)
{
    int parent[v];
    fill(visited, visited + v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            AP_Bridges(graph, new int[v], new int[v], parent, new bool[v], visited, i);
            for (int j = 0; j < v; j++)
            {
                if (visited[j])
                {
                    count++;
                }
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v);
    for (int i = 0; i < v; i++)
    {
        g[i] = vector<int>();
    }
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1 - 1].push_back(v2 - 1);
        g[v2 - 1].push_back(v1 - 1);
    }

    bool A_point[v];
    int count = 0;
    DFS(g, v, A_point, count);
    cout << count << endl;

    return 0;
}
