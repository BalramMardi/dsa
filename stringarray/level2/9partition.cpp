#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;

    map<char, int> mp;

    for (int i = 0; i < str.length(); i++)
    {
        mp[str[i]] = i;
    }

        int prev = -1;
    int maxx = 0;
    vector<int> ans;
    for (int i = 0; i < str.length(); i++)
    {
        maxx = max(maxx, mp[str[i]]);
        if (maxx == i)
        {
            // maxx = mp[str[i]];
            ans.push_back(maxx - prev);
            prev = maxx;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << endl;
    }
}