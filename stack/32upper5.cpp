#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto itr = upper_bound(a, a + n, 3);
    cout << *itr;
}