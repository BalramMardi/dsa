// Efficient CPP program to find length of
// the longest prefix which is also suffix
#include <bits/stdc++.h>
using namespace std;
int longestPrefixSuffix(string str)
{
    vector<int> Lps(str.size(), 0);
    int len = 0, i = 1;
    while (i < str.size())
    {
        if (str[i] == str[len])
        {
            len++;
            Lps[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
                len = Lps[len - 1];
            else
            {
                Lps[i] = 0;
                i++;
            }
        }
    }
    return Lps.back();
}

int main()
{
    string s = "abadabab";
    cout << longestPrefixSuffix(s);
    return 0;
}

/* int longestPrefixSuffix(string str)
{
    vector<int> Lps(str.size(), 0);
    int len = 0, i = 1;
    while (i < str.size())
    {
        if (str[i] == str[len])
        {
            Lps[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if (len == 0)
                i++;
            else
                len = Lps[len - 1];
        }
    }
    return Lps.back();
}
 */