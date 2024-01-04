// find element that appears ones while other appear twice...

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

    for (auto x : vec)
    {
        uni = uni ^ x;
    }

    cout << uni;
}