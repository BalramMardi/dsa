#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minCostToSupplyWater(int n, vector<int> &wells, vector<pair<int, pair<int, int>>> &pipes)
{
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < pipes.size(); i++)
    {
        int u = pipes[i].second.first;
        int v = pipes[i].second.second;
        int wt = pipes[i].first;
        graph[u].emplace_back(v, wt);
        graph[v].emplace_back(u, wt);
    }

    for (int i = 0; i < wells.size(); i++)
    {
        int u = 0;
        int v = i + 1;
        int wt = wells[i];
        graph[u].emplace_back(v, wt);
        graph[v].emplace_back(u, wt);
    }

    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    vector<bool> vis(n + 1, false);

    while (!pq.empty())
    {
        pair<int, int> rem = pq.top();
        pq.pop();

        if (vis[rem.second])
        {
            continue;
        }

        vis[rem.second] = true;
        ans += rem.first;

        vector<pair<int, int>> &nbrs = graph[rem.second];

        for (pair<int, int> &nbr : nbrs)
        {
            if (!vis[nbr.first])
            {
                pq.push(make_pair(nbr.second, nbr.first));
            }
        }
    }

    return ans;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> wells(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wells[i];
    }

    vector<pair<int, pair<int, int>>> pipes(e);

    for (int i = 0; i < e; i++)
    {
        cin >> pipes[i].second.first >> pipes[i].second.second >> pipes[i].first;
    }

    cout << minCostToSupplyWater(n, wells, pipes) << endl;

    return 0;
}
