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

    int maxx = 0;
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        maxx = max(maxx, arr[i]);
        if (maxx == i)
        {
            count++;
        }
    }
    cout << count;
}