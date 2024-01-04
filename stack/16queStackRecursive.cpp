#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class queued
{
    stack<int> s1;

public:
    void push(int x)
    {
        s1.push(x);
    }
    int pop()
    {
        if (s1.empty())
        {
            cout << "queue is empty";
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if (s1.empty())
        {
            return x;
        }
        int topval = pop();

        s1.push(x);
        return topval;
    }

    bool empty()
    {
        if (s1.empty())
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