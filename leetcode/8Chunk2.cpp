#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;

    int arr[num];

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    int right[num + 1];

    right[num] = INT_MAX;

    for (int i = num - 1; i >= 0; i--)
    {

        right[i] = min(right[i + 1], arr[i]);
    }

    int left = INT_MIN;

    int count = 0;
    for (int i = 0; i < num; i++)
    {
        left = max(left, arr[i]);
        if (left <= right[i + 1])
        {
            count++;
        }
    }

    cout << count;
}