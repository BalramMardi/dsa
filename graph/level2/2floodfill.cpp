#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &arr, vector<vector<bool>> &vis, int initial, int x, int y, int i, int j)
{

    if (i < 0 || j < 0 || j >= vis[0].size() || i >= vis.size() || arr[i][j] != initial || vis[i][j])
        return;

    vis[i][j] = true;
    arr[i][j] = 4;
    dfs(arr, vis, initial, x, y, i + 1, j);
    dfs(arr, vis, initial, x, y, i - 1, j);
    dfs(arr, vis, initial, x, y, i, j + 1);
    dfs(arr, vis, initial, x, y, i, j - 1);
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++)
        {
            int res;
            cin >> res;
            ans.push_back(res);
        }
        arr.push_back(ans);
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int initial;
    int x, y;
    cin >> x >> y;
    initial = arr[x][y];
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == initial and vis[i][j] == false)
            {
                dfs(arr, vis, initial, i, j, x, y);
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}