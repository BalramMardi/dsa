#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

void DFS(vector<vector<int>> &adj, int v, vector<bool> &visited, stack<int> &Stack)
{
    visited[v] = true;
    for (int i : adj[v])
    {
        if (!visited[i])
        {
            DFS(adj, i, visited, Stack);
        }
    }
    Stack.push(v);
}

void reverseDFS(vector<vector<int>> &revAdj, int v, vector<bool> &visited, vector<int> &component)
{
    visited[v] = true;
    component.push_back(v);
    for (int i : revAdj[v])
    {
        if (!visited[i])
        {
            reverseDFS(revAdj, i, visited, component);
        }
    }
}

vector<vector<int>> findSCCs(vector<vector<int>> &adj, vector<vector<int>> &revAdj, int V)
{
    vector<bool> visited(V, false);
    stack<int> Stack;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(adj, i, visited, Stack);
        }
    }

    vector<vector<int>> SCCs;

    // Reuse visited vector for reverseDFS
    visited.assign(V, false);

    while (!Stack.empty())
    {
        int v = Stack.top();
        Stack.pop();
        if (!visited[v])
        {
            vector<int> component;
            reverseDFS(revAdj, v, visited, component);
            SCCs.push_back(component);
        }
    }

    return SCCs;
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    vector<vector<int>> revAdj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);

    // Create the reverse graph
    for (int i = 0; i < V; i++)
    {
        for (int j : adj[i])
        {
            revAdj[j].push_back(i);
        }
    }

    vector<vector<int>> SCCs = findSCCs(adj, revAdj, V);

    cout << "Strongly Connected Components:\n";
    for (vector<int> component : SCCs)
    {
        for (int vertex : component)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
