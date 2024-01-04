#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int arr[10] = {1, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        long x = arr[c];
        long y = arr[c];

        while (x < arr[a])
        {
            x *= 2;
        }
        while (y < arr[b])
        {
            y *= 3;
        }

        cout << x << " " << y << endl;
    }
}