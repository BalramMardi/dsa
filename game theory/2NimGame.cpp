#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int xorx = 0;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        xorx = xorx ^ arr[i];
    }

    if (xorx == 0)
    {
        cout << "BOB";
    }
    else
    {
        cout << "ALICE";
    }
}