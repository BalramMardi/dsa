#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string oname, wname;
    cin >> oname >> wname;

    int i = 0;
    int j = 0;
    bool flag = true;
    while (i < oname.length() and j < wname.length())
    {
        if (oname.at(i) == wname.at(j))
        {
            i++;
            j++;
        }
        else if (i > 0 and oname.at(i - 1) == wname.at(j))
        {
            j++;
        }
        else
        {
            flag = false;
        }
    }

    cout << flag;
}