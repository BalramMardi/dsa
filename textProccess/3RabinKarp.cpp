#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "name";
    long MOD = 1000000007;
    long p = 31;
    long pow = 31;
    long ans = s[0] - 'a' + 1;

    for (int i = 0; i < s.length(); i++)
    {
        ans = (ans + (s[i] - 'a' + 1) * pow) % MOD;
        pow = (pow * p) % MOD;
    }

    cout << ans;
}