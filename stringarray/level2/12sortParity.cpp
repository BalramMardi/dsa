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

    int i = 0;
    int j = 0;

    while (i < num)
    {
        if (arr[i] % 2 == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    for (auto x : arr)
    {
        cout << x << " ";
    }
}