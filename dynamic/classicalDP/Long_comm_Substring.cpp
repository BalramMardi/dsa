#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    /* string s1 = "GeeksforGeeks";
    string s2 = "GeeksQuiz"; */

    string s1 = "manss";
    string s2 = "mango";

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

    int max = 0;

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            char c1 = s1[i - 1];
            char c2 = s2[j - 1];

            if (c1 != c2)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if (dp[i][j] > max)
            {
                max = dp[i][j];
            }
        }
    }
    cout << max;
}
