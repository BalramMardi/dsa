#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int num;
    cin >> num;
    string str = to_string(num);
    // string str;
    // cin >> str;

    char ch[str.length() + 1];

    for (int i = 0; i < str.length(); i++)
    {
        ch[i] = str[i];
    }

    int i = str.length() - 2;

    while (i >= 0 and ch[i] >= ch[i + 1])
    {
        i--;
    }

    if (i == -1)
    {
        cout << "-1";
    }

    int j = str.length() - 1;
    while (ch[i] >= ch[j])
    {
        j--;
    }

    char temp = ch[i];
    ch[i] = ch[j];
    ch[j] = temp;

    string res = "";
    for (int d = 0; d <= i; d++)
    {
        res += ch[d];
    }

    for (int f = str.length() - 1; f > i; f--)
    {
        res += ch[f];
    }

    cout << res;
}