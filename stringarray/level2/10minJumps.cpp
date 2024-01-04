#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int jumps = 1;
    int sum = 0;

    while (sum < n)
    {
        sum += jumps;
        jumps++;
    }

    if ((sum - n) % 2 == 0)
    {
        cout << jumps - 1;
    }
    else if ((sum + jumps - n) % 2 == 0)
    {
        cout << jumps;
    }
    else
    {
        cout << jumps + 1;
    }
}