#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void longSub(string s)
{

    int len = s.length();
    vector<vector<int>> dp(len + 1, vector<int>(len + 1));

    for (int i = len; i >= 0; i--)
    {
        for (int j = len; j >= 0; j--)
        {
            if (i == len and j == len)
            {
                dp[i][j] = 0;
            }
            else if (i == len)
            {
                dp[i][j] = 0;
            }
            else if (j == len)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (s[i] == s[j] and i != j)
                {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
    }

    cout << dp[0][0];
}

int main()
{
    string s = "axxxy";
    longSub(s);
}