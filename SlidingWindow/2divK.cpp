#include <iostream>
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
using namespace std;

int div(int arr[], int n, int k)
{

    if (k > n)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    int winsum = sum;
    for (int i = k; i < n; i++)
    {
        winsum += arr[i] - arr[i - k];
        if (winsum % 3 == 0)
        {
            sum = max(winsum, sum);
        }
    }

    if (sum % 3 == 0)
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
    int k;
    cin >> k;
    cout << div(arr, n, k);
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