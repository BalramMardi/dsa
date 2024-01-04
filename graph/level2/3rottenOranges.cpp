#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rottenOrange(vector<vector<int>> &adj)
{
    int n = adj.size();
    int m = adj[0].size();

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    int vis[n][m];

    queue<pair<pair<int, int>, int>> q;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }

            if (adj[i][j] == 1)
                count++;
        }
    }
    int cnt = 0, tm = 0;
    while (!q.empty())
    {
        int row = q.front().first.first;  // row index
        int col = q.front().first.second; // col index
        int t = q.front().second;         // time an orange at a
                                          // cell takes to rot.
        q.pop();

        tm = max(tm, t);

        // checking for adjacent nodes in 4 directions.
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // checking the validity of a node and also
            // vis[nrow][ncol] !=2
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && adj[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
            {
                vis[nrow][ncol] = 2; // adj orange is rotten
                q.push({{nrow, ncol},
                        t + 1}); // incrementing time for
                                 // that orange by 1
                cnt++;
            }
        }
    }

    return (cnt == count) ? tm : -1;
}

int main()
{
    vector<vector<int>> adj = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};

    cout << rottenOrange(adj);
}