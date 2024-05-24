#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void dfs(int node, vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int &reorderCount)
{
    visited[node] = true;
    for (const auto it : graph[node])
    {
        if (!visited[it.first])
        {
            reorderCount += it.second;
            dfs(it.first, graph, visited, reorderCount);
        }
    }
}

int minReorder(int n, vector<vector<int>> &connections)
{
    vector<vector<pair<int, int>>> graph(n);
    for (const auto &conn : connections)
    {
        graph[conn[0]].emplace_back(conn[1], 1); // original direction
        graph[conn[1]].emplace_back(conn[0], 0); // reverse direction
    }

    vector<bool> visited(n, false);
    int reorderCount = 0;

    dfs(0, graph, visited, reorderCount);

    return reorderCount;
}

int main()
{
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    int n = 6;
    cout << "Minimum number of reorders: " << minReorder(n, connections) << endl;
    return 0;
}
