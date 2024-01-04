#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);

    for (int ii = 0; ii < n; ii++)
    {
        cin >> arr1[ii];
    }
    for (int ii = 0; ii < m; ii++)
    {
        cin >> arr2[ii];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0;
    while (arr1[i] == 0)
    {
        i++;
    }
    int j = 0;
    while (arr2[j] == 0)
    {
        j++;
    }

    while (i < arr1.size() and j < arr2.size())
    {
        if (arr1[i] != arr2[j])
        {
            cout << "Alice";
            break;
        }
        i++;
        j++;
    }
    if (i == arr1.size() and j == arr2.size())
    {
        cout << "Bob";
    }
    else
    {
        cout << "Alice";
    }
}