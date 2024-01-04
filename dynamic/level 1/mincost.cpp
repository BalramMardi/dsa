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

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == dp.size() - 1 && j == dp[0].size() - 1)
            {
                dp[i][j] = vec[i][j];
            }
            else if (i == dp.size() - 1)
            {
                dp[i][j] = vec[i][j] + dp[i][j + 1];
            }
            else if (j == dp[0].size() - 1)
            {
                dp[i][j] = vec[i][j] + dp[i + 1][j];
            }
            else
            {
                dp[i][j] = vec[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    cout << dp[0][0];
}