#include <iostream>
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
using namespace std;

int sumK(int arr[], int n, int k, int x)
{

    if (n < k)
    {
        cout << "Invalid";
        return -1;
    }
    int sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    int winsum = sum;
    for (int i = k; i < n; i++)
    {
        winsum += arr[i] - arr[i - k];
        sum = max(sum, winsum);
    }

    if (sum < x)
        return sum;

    else
        return -1;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k, x;
    cin >> k >> x;
    cout << sumK(arr, n, k, x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}