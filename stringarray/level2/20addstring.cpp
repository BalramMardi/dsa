#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2)
{
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    int carry = 0;
    string res = "";
    while (i >= 0 or j >= 0 or carry)
    {
        int ival = i >= 0 ? num1[i] - '0' : 0;
        int jval = j >= 0 ? num2[j] - '0' : 0;

        i--;
        j--;

        int sum = ival + jval + carry;
        res = to_string(sum % 10) + (res);
        carry = sum / 10;
    }
    return res;
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    string res = addStrings(str1, str2);
    cout << res;
}