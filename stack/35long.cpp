// longest substring easy way

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin >> s;

    int count[256] = {0};
    int l = 0;
    int r = 0;
    int ans = 0;

    while (r < s.length())
    {
        count[s[r]]++;
        while (count[s[r]] > 1)
        {
            count[s[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans;
}

// Time Comp = O(n);
// Space Comp = O(256);
