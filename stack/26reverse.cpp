#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse(string s)
{
    stack<string> stack;

    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' and i < s.length())
        {
            word += s[i];
            i++;
        }
        stack.push(word);
    }

    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
int main()
{

    string s = "how you doin?";
    reverse(s);
}