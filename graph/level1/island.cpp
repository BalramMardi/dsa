#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<bool>>& vis, int i, int j, vector<vector<int>>& arr)
{
  if (i < 0 || j < 0 || j >= vis[0].size() || i >= vis.size() || arr[i][j] == 1 || vis[i][j])
    return;

  vis[i][j] = true;
  dfs(vis, i + 1, j, arr);
  dfs(vis, i - 1, j, arr);
  dfs(vis, i, j + 1, arr);
  dfs(vis, i, j - 1, arr);
}

int countIsland(vector<vector<bool>>& vis, vector<vector<int>>& arr)
{
  int cnt = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 0; j < arr[0].size(); j++)
    {
      if (arr[i][j] == 0 && vis[i][j] == false)
      {
        cnt++;
        dfs(vis, i, j, arr);
      }
    }
  }
  return cnt;
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
  cout << countIsland(vis, arr);
}