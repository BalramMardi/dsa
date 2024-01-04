#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class interval
{
public:
    int start;
    int end;
    interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

bool compare(interval i1, interval i2)
{
    return i1.start < i2.start;
}

stack<interval> merge(interval arr[])
{
    stack<interval> stack;

    sort(arr, arr + 4, compare);

    stack.push(arr[0]);
    for (int i = 1; i < 4; i++)
    {
        interval uppar = stack.top();

        if (uppar.end < arr[i].start)
        {
            stack.push(arr[i]);
        }
        else if (uppar.end < arr[i].end)
        {
            uppar.end = arr[i].end;
            stack.pop();
            stack.push(uppar);
        }
    }

    return stack;
}

int main()
{
    interval arr[] = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    stack<interval> stack2 = merge(arr);
    stack<interval> stack;

    while (!stack2.empty())
    {
        stack.push(stack2.top());
        stack2.pop();
    }

    cout << "\n The Merged Intervals are: ";
    while (!stack.empty())
    {
        interval t = stack.top();
        cout << "[" << t.start << "," << t.end << "] ";
        stack.pop();
    }
}