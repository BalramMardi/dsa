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

int main()
{

    int n;
    cin >> n;
    vector<int> arr(100001);
    sieve(arr);

    while (n--)
    {
        int t;
        cin >> t;
        vector<int> ans = factor(arr, t);

        for (auto val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}