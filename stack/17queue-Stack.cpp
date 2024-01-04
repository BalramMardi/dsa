#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class queued
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }
    int pop()
    {
        if (s1.empty() and s2.empty())
        {
            cout << "queue is empty";
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool empty()
    {
        if (s1.empty() and s2.empty())
            return true;

        return false;
    }
};

int main()
{
    queued q;
    q.push(1);
    q.push(2);
    q.pop();
    q.push(3);
    while (!q.empty())
    {
        cout << q.pop();
    }
}