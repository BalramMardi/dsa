#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjL[], int vis[])
{
    vis[node] = 1;
    for (auto it : adjL[node])
    {
        if (!vis[it])
            dfs(it, adjL, vis);
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    vector<int> adjL[V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 and i != j)
            {
                adjL[i].push_back(j);
                adjL[j].push_back(i);
            }
        }
    }

    int vis[V] = {0};
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adjL, vis);
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    cout << numProvinces(adj, 3);
}