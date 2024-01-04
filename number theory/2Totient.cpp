#include <iostream>
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
using namespace std;

int eulerTotient(int n)
{

    int count = n;
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            count = count - (count / i);
        }
        while (n % i == 0)
        {
            n = n / i;
        }
    }

    if (n > 1)
    {
        count = count - (count / n);
    }
    return count;
}

void solve()
{
    int n;
    cin >> n;
    cout << eulerTotient(n);
    cout << endl;
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