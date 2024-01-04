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
    for (int i = 1; i < num; i++)
    {
        mul = mul * arr[i];
    }

    int newarr[num];
    newarr[0] = mul;

    for (int i = 1; i < num; i++)
    {
        newarr[i] = mul / arr[i];
    }

    for (int i = 0; i < num; i++)
    {
        cout << newarr[i] << endl;
    }
}