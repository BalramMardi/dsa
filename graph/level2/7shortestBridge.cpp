#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

void dfs(int i, int j, vector<vector<int>> grid, queue<pair<int, int>> &q, vector<vector<bool>> &vis)
{
    vis[i][j] = true;
    q.push({i, j});
    for (int k = 0; k < 4; k++)
    {
        int rowdash = i + dir[k][0];
        int coldash = j + dir[k][1];

        if (rowdash < 0 or coldash < 0 or rowdash >= grid.size() or coldash >= grid[0].size() or vis[rowdash][coldash] == true or grid[rowdash][coldash] == 0)
        {
            continue;
        }

        dfs(rowdash, coldash, grid, q, vis);
    }
}

int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    bool flag = false;

    for (int i = 0; i < n and !flag; i++)
    {
        for (int j = 0; j < m and !flag; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(i, j, grid, q, vis);
                flag = true;
            }
        }
    }

    int level = 0;
    while (q.size())
    {

        int size = q.size();

        while (size--)
        {

            // Pair rem = q.front();
            int rowrem = q.front().first;
            int colrem = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                // int rowdash = rem.first + dir[i][0];
                // int coldash = rem.second + dir[i][1];

                int rowdash = rowrem + dir[i][0];
                int coldash = colrem + dir[i][1];

                if (rowdash < 0 or coldash < 0 or rowdash >= grid.size() or coldash >= grid[0].size() or vis[rowdash][coldash] == true)
                {
                    continue;
                }

                if (grid[rowdash][coldash] == 1)
                {
                    return level;
                }
                q.push({rowdash, coldash});
            }
        }
        level++;
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = shortestBridge(grid);
    cout << ans;
}