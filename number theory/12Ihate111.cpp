#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> factor(vector<int> arr, int n)
{
    vector<int> ans;
    while (n > 1)
    {
        ans.push_back(arr[n]);
        n = n / arr[n];
    }
    return ans;
}
void sieve(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i * i < arr.size(); i++)
    {
        if (arr[i] == i)
        {
            for (int j = i * i; j < arr.size(); j += i)
            {
                if (arr[j] == j)
                {
                    arr[j] = i;
                }
            }
        }
    }
}
int gcd(int a, int b)
{

    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int power(long x, unsigned int y)
{
    int res = 1;

    if (x == 0)
        return 0;

    while (y > 0)
    {

        if (y & 1) // to check for odd number
        {
            res = (res * x);
            y--;
        }

        y = y >> 1; // y = y/2
        x = (x * x);
    }
    return res;
}

void solve()
{
    long x, b;
    cin >> x;
    b = x % 11;
    vector<string> ans;

    long val = x - 111 * b;

    if (val >= 0 and (val % 11 == 0))
    {
        ans.push_back("YES");
    }
    else
    {
        ans.push_back("NO");
    }

    for (auto tt : ans)
    {
        cout << tt << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}