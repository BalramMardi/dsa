// stock LTR
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void gtr(int arr[], int n)
{

    stack<int> stacky;
    int result[n];
    stacky.push(0);
    result[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (!stacky.empty() && arr[stacky.top()] < arr[i])
        {
            stacky.pop();
        }

        if (stacky.empty())
        {
            result[i] = i + 1;
        }
        else
        {
            result[i] = i - stacky.top();
        }

        stacky.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    int arr[] = {10, 4, 5, 90, 120, 80};
    int n = 6;
    gtr(arr, n);
}