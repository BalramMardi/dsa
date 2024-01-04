#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    int end = -1;
    int max = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
        else
        {
            end = i;
        }
    }

    int st = 0;
    int min = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
        else
        {
            st = i;
        }
    }

    return end - st + 1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec = {2, 6, 4, 8, 10, 9, 15};
    int ans = findUnsortedSubarray(vec);
    cout << ans;
}