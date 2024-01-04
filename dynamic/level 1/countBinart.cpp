// the Count Binary String question where we are required to find all the binary strings of length with no consecutive zero's.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;

    int oldzero = 1;
    int oldone = 1;

    int newone = 0;
    int newzero = 0;

    for (int i = 2; i <= n; i++)
    {
        newzero = oldone;
        newone = oldone + oldzero;

        oldone = newone;
        oldzero = newzero;
    }

    cout << oldzero + oldone;
}