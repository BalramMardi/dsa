#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int uni = 0;
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    int xxty = 0;

    for (auto val : vec)
    {
        xxty = xxty ^ val;
    }

    int rsbm = xxty & -xxty;
    int x = 0;
    int y = 0;

    for (int val : vec)
    {
        if (val & rsbm == 0)
        {
            x = x ^ val;
        }
        else
        {
            y = y ^ val;
        }
    }

    if (x < y)
    {
        cout << x;
        cout << endl;
        cout << y;
    }
    else
    {
        cout << y;
        cout << endl;

        cout << x;
    }
}