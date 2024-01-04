#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (i % 2 == 0)
        {
            if (nums[i + 1] < nums[i])
            {
                swap(nums[i + 1], nums[i]);
            }
        }
        else
        {
            if (nums[i + 1] > nums[i])
            {
                swap(nums[i + 1], nums[i]);
            }
        }
    }
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

    wiggleSort(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}
