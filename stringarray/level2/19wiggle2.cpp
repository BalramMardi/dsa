#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> wiggleSort(vector<int> &nums)
{
    vector<int> ans;

    sort(ans.begin(), ans.end());
    int n = nums.size();
    vector<int> ans(n);
    int i = 1;
    int j = n - 1;
    while (i < n)
    {
        ans[i] = nums[j];
        i += 2;
        j--;
    }
    j = 0;
    while (i < n)
    {
        ans[i] = nums[j];
        i += 2;
        j--;
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = ans[i];
    }

    return nums;
}

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = wiggleSort(nums);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}