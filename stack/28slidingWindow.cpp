#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void slidingWindow(int arr[], int n, int k)
{
    deque<int> q(k);

    for (int i = 0; i < k; i++)
    {
        /* code */
        while (!q.empty() and arr[i] >= arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        cout << arr[q.front()] << " ";

        while (!q.empty() and q.front() <= i - k)
        {
            q.pop_front();
        }

        while (!q.empty() and arr[i] >= arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    cout << arr[q.front()] << " ";
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

    // Function call
    slidingWindow(arr, N, K);
}