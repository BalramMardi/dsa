#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string rec(int count)
{

    if (count == 0)
    {
        return "";
    }
    count--;

    char ch = 'A' + count % 26;

    return rec(count / 26) + ch;
}

int main()
{
    int n;
    cin >> n;

    cout << rec(n);
}