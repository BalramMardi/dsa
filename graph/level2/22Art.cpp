// C++ program to find articulation points in an undirected graph
#include <bits/stdc++.h>
using namespace std;

void APUtil(vector<int> adj[], int u, bool visited[], int disc[], int low[], int &time, int parent, bool isAP[])
{
    // Count of children in DFS Tree
    int children = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices adjacent to this
    for (auto v : adj[u])
    {
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;

            // Your modified logic
            if (parent == u && children == 1)
                continue;

            APUtil(adj, v, visited, disc, low, time, u, isAP);

            // Check if the subtree rooted with v has
            // a connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If u is not root and low value of one of
            // its child is more than discovery value of u.
            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = true;
        }

        // Update low value of u for parent function calls.
        else if (v != parent)
            low[u] = min(low[u], disc[v]);
    }

    // Your additional conditions
    if (parent == -1 && children >= 2)
        isAP[u] = true;
    else if (parent != -1 && low[u] >= disc[u])
        isAP[u] = true;
}

void AP(vector<int> adj[], int V)
{
    int disc[V] = {0};
    int low[V];
    bool visited[V] = {false};
    bool isAP[V] = {false};
    int time = 0, par = -1;

    // disconnected graph
    for (int u = 0; u < V; u++)
        if (!visited[u])
            APUtil(adj, u, visited, disc, low,
                   time, par, isAP);

    // Printing the APs
    for (int u = 0; u < V; u++)
        if (isAP[u] == true)
            cout << u << " ";
}

// Utility function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    // Create graphs given in above diagrams
    cout << "Articulation points in first graph \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    AP(adj1, V);

    cout << "\nArticulation points in second graph \n";
    V = 4;
    vector<int> adj2[V];
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 2, 3);
    AP(adj2, V);

    cout << "\nArticulation points in third graph \n";
    V = 7;
    vector<int> adj3[V];
    addEdge(adj3, 0, 1);
    addEdge(adj3, 1, 2);
    addEdge(adj3, 2, 0);
    addEdge(adj3, 1, 3);
    addEdge(adj3, 1, 4);
    addEdge(adj3, 1, 6);
    addEdge(adj3, 3, 5);
    addEdge(adj3, 4, 5);
    AP(adj3, V);

    cout << "\nArticulation points in forth graph \n";

    V = 5;
    vector<int> adj4[V];
    addEdge(adj4, 0, 1);
    addEdge(adj4, 2, 3);
    addEdge(adj4, 3, 4);

    AP(adj4, V);

    cout << "\nArticulation points in forth graph \n";

    V = 6;
    vector<int> adj5[V];
    addEdge(adj5, 0, 1);
    addEdge(adj5, 5, 1);
    addEdge(adj5, 2, 3);
    addEdge(adj5, 3, 4);

    AP(adj5, V);

    return 0;
}
