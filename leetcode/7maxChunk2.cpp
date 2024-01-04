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

    int left[num + 1];
    int right[num + 1];

    left[0] = arr[0];
    right[num] = INT_MAX;
    for (int i = 1; i < num + 1; i++)
    {

        left[i] = max(left[i - 1], arr[i]);
    }
    for (int i = num - 1; i >= 0; i--)
    {

        right[i] = min(right[i + 1], arr[i]);
    }

    int count = 0;
    for (int i = 0; i < num; i++)
    {
        if (left[i] <= right[i + 1])
        {
            count++;
        }
    }

    cout << count;
}