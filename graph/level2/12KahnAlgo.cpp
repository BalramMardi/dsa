#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kahnsTopologicalSort(vector<vector<int>> &graph, vector<int> &inDegree)
{
    int n = graph.size();
    vector<int> result;
    queue<int> q;

    for (int i = 0; i < n; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : graph[node])
        {
            --inDegree[neighbor];
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // ++inDegree[v];
        inDegree[v] = inDegree[v] + 1;
    }

    vector<int> sortedOrder = kahnsTopologicalSort(graph, inDegree);

    if (sortedOrder.size() == n)
    {

        for (int node : sortedOrder)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Graph contains a cycle, cannot perform topological sorting." << endl;
    }

    return 0;
}
