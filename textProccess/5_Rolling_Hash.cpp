#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rolling(string s1, string s2)
{

    long MOD = 1000000007;
    long p = 31;
    long pow = p;
    long dhv = s2[0] - 'a' + 1;

    for (int i = 1; i < s2.length(); i++)
    {
        dhv = (dhv + (s2[i] - 'a' + 1) * pow) % MOD;
        pow = (pow * p) % MOD;
    }

    // Rabin Karp
    long dp[s1.length()];
    long pa[s1.length()];

    dp[0] = s1[0] - 'a' + 1;
    pa[0] = 1;

    pow = p;
    for (int i = 1; i < s1.length(); i++)
    {
        dp[i] = ((dp[i - 1] + (s1[i] - 'a' + 1) * pow)) % MOD;
        pa[i] = pow;
        pow = (pow * p) % MOD;
    }

    int sp = 0, ep = s2.length() - 1;
    vector<int> ans;

    while (ep < s1.length())
    {
        long win = dp[ep];
        if (sp > 0)
        {
            win = (win - dp[sp - 1] + MOD) % MOD;
        }
        if (win == (dhv * pa[sp]) % MOD)
        {
            ans.push_back(sp + 1);
        }
        sp++;
        ep++;
    }

    for (auto it : ans)
    {
        cout << it;
    }
    cout << endl;

    cout << ans.size();
}

int main()
{

    string s1 = "jbjbgeeksfo";
    string s2 = "geeks";

    rolling(s1, s2);
}