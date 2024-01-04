#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc,
         vector<int> &low, vector<int> &result, unordered_map<int, list<int>> &adjList,
         vector<bool> &visited)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto neigh : adjList[node])
    {
        if (!visited[neigh])
        {
            child++;
            dfs(neigh, node, timer, disc, low, result, adjList, visited);
            low[node] = min(low[node], low[neigh]);

            if (low[neigh] >= disc[node])
                result.push_back(node);
        }
        else if (neigh != parent)
        {
            low[node] = min(low[node], disc[neigh]);
        }
    }

    if (parent == -1 && child > 1)
        result.push_back(node);
}

vector<int> cutVertex(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> visited(n, false);
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, -1, timer, disc, low, result, adjList, visited);
    }

    return result;
}

int main()
{
    vector<vector<int>> edges;
    int n, m;

    cin >> n;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> answer = cutVertex(edges, n, m);
    sort(answer.begin(), answer.end());

    cout << "Articulation Points : ";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
