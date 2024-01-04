#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// typedef pair<int, int> Pair;

int maxDistance(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

    if (q.size() == 0 or q.size() == (grid.size() * grid[0].size()))
    {
        return -1;
    }

    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int level = -1;
    while (q.size())
    {
        level++;
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

                if (rowdash < 0 or coldash < 0 or rowdash >= grid.size() or coldash >= grid[0].size() or grid[rowdash][coldash] == 1)
                {
                    continue;
                }
                q.push({rowdash, coldash});
                grid[rowdash][coldash] = 1;
            }
        }
    }
    return level;
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

    int ans = maxDistance(grid);
    cout << ans;
}