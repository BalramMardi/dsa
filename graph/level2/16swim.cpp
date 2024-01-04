#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> iPair;

int swim(vector<vector<int>> grid)
{

    int n = grid.size();
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<vector<int>> vis(n, vector<int>(n, false));

    pq.push({grid[0][0], {0, 0}});

    while (pq.size())
    {
        iPair rem = pq.top();
        pq.pop();

        if (rem.second.first == n - 1 and rem.second.second == n - 1)
        {
            return rem.first;
        }

        if (vis[rem.second.first][rem.second.second])
        {
            continue;
        }
        vis[rem.second.first][rem.second.second] = true;

        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (int i = 0; i < 4; i++)
        {
            int rowd = rem.second.first + dirs[i][0];
            int cold = rem.second.second + dirs[i][1];

            if (rowd < 0 or cold < 0 or rowd >= n or cold >= n or vis[rowd][cold] == true)
            {
                continue;
            }
            pq.push({max(rem.first, grid[rowd][cold]), {rowd, cold}});
        }
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = swim(grid);

    cout << ans;
}