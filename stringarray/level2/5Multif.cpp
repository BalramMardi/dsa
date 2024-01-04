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

    int mul = 1;
    int mur = 1;

    int left[num];
    int right[num];

    for (int i = 0; i < num; i++)
    {
        mul = mul * arr[i];
        left[i] = mul;
    }

    for (int i = num - 1; i >= 0; i--)
    {
        mur = mur * arr[i];
        right[i] = mur;
    }

    int ans[num];
    ans[0] = arr[0];
    ans[num - 1] = left[num - 2];
    for (int i = 1; i < num - 1; i++)
    {
        ans[i] = left[i - 1] * right[i + 1];
    }

    for (int i = 0; i < num; i++)
    {
        cout << ans[i] << endl;
    }
}