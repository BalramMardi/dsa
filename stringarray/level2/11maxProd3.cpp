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

    int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    for (int i = 0; i < num; i++)
    {
        if (arr[i] >= max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] >= max2)
        {
            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] >= max3)
        {
            max3 = arr[i];
        }
        if (arr[i] <= min1)
        {
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] <= min2)
        {
            min2 = arr[i];
        }
    }
    int mul1 = min1 * min2 * max1;
    int mul2 = max3 * max2 * max1;

    cout << max(mul1, mul2);
}