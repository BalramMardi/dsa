#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s, int l, int r)
{

    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s)
{

    int l = 0, r = s.length() - 1;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
        {
            return ispalindrome(s, l + 1, r) || ispalindrome(s, l, r - 1);
        }
    }

    return true;
}

int main()
{
    string str = "chitihc";
    cout << validPalindrome(str);
}