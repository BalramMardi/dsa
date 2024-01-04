#include <iostream>
#include <vector>

using namespace std;

void addEdge(int u, int v, vector<vector<int>> &adj)
{
    adj[u].push_back(v);
}

void DFS(vector<vector<int>> &graph, int v, vector<bool> &visited)
{
    visited[v] = true;
    for (int x : graph[v])
    {
        if (!visited[x])
        {
            DFS(graph, x, visited);
        }
    }
}

int motherVertex(vector<vector<int>> &graph, int V)
{
    vector<bool> visited(V, false);
    int v = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(graph, i, visited);
            v = i;
        }
    }

    vector<bool> check(V, false);
    DFS(graph, v, check);

    for (bool val : check)
    {
        if (!val)
        {
            return -1;
        }
    }

    return v;
}

int main()
{
    int V = 7;
    int E = 8;

    vector<vector<int>> adj(V);

    addEdge(0, 1, adj);
    addEdge(0, 2, adj);
    addEdge(1, 3, adj);
    addEdge(4, 1, adj);
    addEdge(6, 4, adj);
    addEdge(5, 6, adj);
    addEdge(5, 2, adj);
    addEdge(6, 0, adj);

    cout << "A mother vertex is " << motherVertex(adj, V) << endl;

    return 0;
}
