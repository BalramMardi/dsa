#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void smallest(string str)
{

    string result;

    stack<int> stack;
    int count = 1;
    for (int i = 0; i < str.length(); i++)
    {

        stack.push(count);
        count++;

        if (str.at(i) == 'I')
        {

            while (stack.size() > 0)
            {
                cout << stack.top();
                stack.pop();
            }
        }
    }
    stack.push(count);
    while (stack.size() > 0)
    {
        cout << stack.top();
        stack.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    // smallest("DDIIDDDI");

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        smallest(str);
    }
}