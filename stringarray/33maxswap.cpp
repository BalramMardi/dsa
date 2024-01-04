#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void maxSwap(vector<int> arr)
{
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]] = i;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }
    maxSwap(arr);
}