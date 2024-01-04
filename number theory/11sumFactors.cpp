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

int main()
{

    long t;
    cin >> t;
    vector<int> arr(100001);
    sieve(arr);

    vector<int> res;
    while (t--)
    {
        long n;
        cin >> n;

        vector<int> list = factor(arr, n);

        if (n == 1)
        {
            res.push_back(0);
            continue;
        }

        int prd = 1;
        int count = 1;

        for (int i = 1; i < list.size(); i++)
        {
            if (list[i] == list[i - 1])
            {
                count++;
            }
            else
            {
                long pow = power(list[i - 1], count + 1);
                prd = prd * ((pow - 1) / (list[i - 1] - 1));
                count = 1;
            }
        }
        long pow = power(list[list.size() - 1], count + 1);
        prd = prd * ((pow - 1) / (list[list.size() - 1] - 1));

        res.push_back(prd - n);
    }

    for (auto x : res)
    {
        cout << x << " ";
    }

    cout << endl;
}