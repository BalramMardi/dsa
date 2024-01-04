#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

string reverseVowels(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {

        while (left < right && !isVowel(s[left]))
        {
            left++;
        }

        if (left < right and !isVowel(s[right]))
        {
            right--;
        }

        swap(s[left], s[right]);

        left++;
        right--;
    }

    return s;
}
int main()
{
    string str;
    str = "leetcode";
    string ans = reverseVowels(str);
    cout << ans;
}