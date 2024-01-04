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

int main()
{

    int n;
    cin >> n;
    vector<int> arr(100001);
    sieve(arr);

    vector<int> res;
    while (n--)
    {
        int a, b;
        cin >> a >> b;

        int temp = gcd(a, b);

        if (temp == 1)
        {
            res.push_back(1);
            continue;
        }

        vector<int> list = factor(arr, temp);

        int ans = 1;
        int count = 1;

        for (int i = 1; i < list.size(); i++)
        {
            if (list[i] == list[i - 1])
            {
                count++;
            }
            else
            {
                ans = ans * (count + 1);
                count = 1;
            }
        }
        ans = ans * (count + 1);

        res.push_back(ans);
    }

    for (auto x : res)
    {
        cout << x << " ";
    }

    cout << endl;
}