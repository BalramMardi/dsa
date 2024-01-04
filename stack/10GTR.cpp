#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void gtr(int arr[], int n)
{
    stack<int> stacky;
    stack<int> result;

    for (int i = n; i >= 1; i--)
    {
        while (!stacky.empty() && stacky.top() <= arr[i - 1])
        {
            stacky.pop();
        }

        if (stacky.empty())
        {
            result.push(-1);
        }
        else
        {
            result.push(stacky.top());
        }

        stacky.push(arr[i - 1]);
    }

    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
}

int main()
{
    int arr[] = {2, 5, 9, 3, 1, 12, 6, 8, 7};
    int n = 9;
    gtr(arr, n);
    return 0;
}
