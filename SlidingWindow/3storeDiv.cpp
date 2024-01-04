#include <iostream>
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
using namespace std;

void div(vector<int> arr, int k)
{

    pair<int, int> handle;
    if (arr.size() < k)
    {
        cout << "invalid" << endl;
        return;
    }

    int sum = 0;
    bool found = false;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];

        if (sum % 3 == 0)
        {
            handle = make_pair(0, k - 1);
            found = true;
        }
    }
    int winsum = sum;

    for (int i = k; i < arr.size(); i++)
    {
        if (found)
        {
            break;
        }

        winsum += arr[i] - arr[i - k];

        if (winsum % 3 == 0)
        {
            handle = make_pair(i - k + 1, i);
            found = true;
        }
    }

    if (!found)
    {
        handle = make_pair(-1, 0);
    }

    if (handle.first == -1)
    {
        cout << "not found";
    }
    else
    {
        for (int i = handle.first; i <= handle.second; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int k;
    cin >> k;

    div(vec, k);
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