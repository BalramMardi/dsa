#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> prices;

    vector<int> np(prices.size() + 1);
    vector<int> dp(np.size());

    for (int i = 0; i < prices.size(); i++)
    {
        np[i + 1] = prices[i];
    }

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < np.size(); i++)
    {

        dp[i] = np[i];
        int li = 1;
        int ri = np.size() - 1;

        while (li <= ri)
        {
            if (dp[i] < dp[li] + dp[ri])
            {
                dp[i] = dp[li] + dp[ri];
            }

            ri--;
            li++;
        }

        cout << dp[dp.size() - 1];
    }
}