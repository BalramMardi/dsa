

#include <bits/stdc++.h>
using namespace std;

bool areBracketsBalanced(string s)
{

    stack<char> temp;
    for (int i = 0; i < s.length(); i++)
    {

        //push if empty
        if (temp.empty())
        {

            temp.push(s[i]);
        }
        //else check for bracket ? pop : push
        else if ((temp.top() == '(' && s[i] == ')') || (temp.top() == '{' && s[i] == '}') || (temp.top() == '[' && s[i] == ']'))
        {

            temp.pop();
        }
        else
        {
            temp.push(s[i]);
        }
    }

    //Check
    if (temp.empty())
    {

        return true;
    }
    return false;
}

int main()
{
    string s = "{()}[]";

    if (areBracketsBalanced(s))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
