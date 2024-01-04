#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void zeroOneBfs(vector<vector<pair<int, int>>> adj)
{
    deque<pair<int, int>> dq;
    int n = adj.size();
    vector<int> vis(n, false);
    dq.push_back({0, 0});

    while (dq.size())
    {
        int vtx = dq.front().first;
        int wt = dq.front().second;
        dq.pop_front();

        if (vtx == n - 1)
        {
            cout << wt;
            return;
        }

        vis[vtx] = true;

        for (pair<int, int> nbrs : adj[vtx])
        {
            if (vis[nbrs.first] == true)
            {
                continue;
            }
            if (nbrs.second == 0)
            {
                dq.push_front({nbrs.first, wt + 0});
            }
            else
            {
                dq.push_back({nbrs.first, wt + 1});
            }
        }
    }
    cout << "-1";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(m);
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--; // Adjusting 0-based indexing
        y--;
        adj[x].push_back({y, 0});
        adj[y].push_back({x, 1});
    }

    zeroOneBfs(adj);
}