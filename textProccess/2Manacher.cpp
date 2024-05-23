#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string updat(string s1)
{
    string str;
    str.append("@");
    for (int i = 0; i < s1.length(); i++)
    {
        str.append("#");
        str += s1[i];
    }
    str.append("#");
    str.append("$");
    return str;
}
void solution(string s1)
{
    string st = updat(s1);
    vector<int> lps(st.length());
    int c = 0;
    int r = 0;
    for (int i = 1; i < st.length() - 1; i++)
    {
        int mirr = c - (i - c);

        if (i < r)
        {
            lps[i] = min(lps[mirr], r - i);
        }
        while ((st[i + lps[i] + 1]) == (st[i - lps[i] - 1]))
        {
            lps[i]++;
        }
        if (i + lps[i] > r)
        {
            c = i;
            r = i + lps[i];
        }
    }
    int maxlen = 0;
    int maxidx = 0;
    for (int i = 1; i < lps.size() - 1; i++)
    {
        if (lps[i] > maxlen)
        {
            maxlen = lps[i];
            maxidx = i;
        }
    }
    cout << maxlen << endl;
    int firstidx = maxidx - maxlen + 1;
    int actidx = (firstidx - 2) / 2;
    cout << s1.substr(actidx, maxlen);
    // cout << s1.substr(firstidx, maxlen);
}

int main()
{
    string name = "babcbabcbaccba";
    string annn = updat(name);

    string s2 = "abcbabcbabcba";

    cout << endl;
    cout << annn << endl;

    solution(name);
    cout << endl;
    solution(s2);
}
