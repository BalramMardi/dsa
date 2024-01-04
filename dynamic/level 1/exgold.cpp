#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    int m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));

    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (j == dp[0].size() - 1)
            {
                dp[i][j] = vec[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = vec[i][j] + max(dp[i + 1][j + 1], dp[i][j + 1]);
            }
            else if (i == dp.size() - 1)
            {
                dp[i][j] = vec[i][j] + max(dp[i - 1][j + 1], dp[i][j + 1]);
            }
            else
            {
                int mm = max(dp[i - 1][j + 1], dp[i][j + 1]);
                dp[i][j] = vec[i][j] + max(dp[i + 1][j + 1], mm);
            }
        }
    }
    int maxGold = dp[0][0];
    for (int i = 0; i < dp.size(); i++)
    {
        maxGold = max(maxGold, dp[i][0]);
    }

    cout << maxGold;
}