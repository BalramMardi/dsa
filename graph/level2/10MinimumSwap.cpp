#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long minimumReplacement(vector<int> &nums)
{
    vector<pair<int, int>> arr;

    for (int i = 0; i < nums.size(); i++)
    {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].first << " " << arr[i].second << endl;
    }

    vector<bool> vis(arr.size(), false);

    long long ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (vis[i] == true or arr[i].second == i)
        {
            continue;
        }
        int clen = 0;
        int j = i;
        while (vis[j] == false)
        {
            vis[j] = true;
            clen++;
            j = arr[j].second;
        }

        ans += (clen - 1);
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long ans = minimumReplacement(arr);
    cout << ans;
}