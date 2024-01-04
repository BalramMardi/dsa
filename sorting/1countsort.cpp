#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countsort(vector<int> &nums)
{
    int n = nums.size();

    int maxx = nums[0];
    for (int i = 0; i < n; i++)
    {
        maxx = max(nums[i], maxx);
    }

    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[nums[i]]++;
    }

    for (int i = 1; i <= maxx; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {

        ans[--count[nums[i]]] = nums[i];
    }

    for (auto j : ans)
    {
        cout << j << " ";
    }
}

int main()
{
    vector<int> nums = {1, 9, 2, 3, 9, 1, 6, 4, 3};
    countsort(nums);
}