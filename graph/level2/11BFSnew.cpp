#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void zeroOneBfs(vector<vector<pair<int, int>>> &graph)
{
    deque<pair<int, int>> queue;
    int n = graph.size();
    vector<bool> vis(n, false);
    queue.push_back(make_pair(0, 0));

    while (!queue.empty())
    {
        pair<int, int> rem = queue.front();
        queue.pop_front();

        if (rem.first == n - 1)
        {
            cout << rem.second << endl;
            return;
        }

        vis[rem.first] = true;

        for (pair<int, int> nbrs : graph[rem.first])
        {
            if (vis[nbrs.first] == true)
            {
                continue;
            }

            if (nbrs.second == 0)
            {
                queue.push_front(make_pair(nbrs.first, rem.second));
            }
            else
            {
                queue.push_back(make_pair(nbrs.first, rem.second + 1));
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; // Adjusting 0-based indexing
        v--;

        graph[u].push_back(make_pair(v, 0));
        graph[v].push_back(make_pair(u, 1));
    }

    zeroOneBfs(graph);

    return 0;
}
