#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, m;
   const int N = 1e5 + 2;
   bool vis[N];

   vector<int> adj[N];

   for (int i = 0; i < N; i++)
   {
      /* code */
      vis[i] = 0;
   }

   cin >> n >> m;
   int x, y;
   for (int i = 0; i < m; i++)
   {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }

   queue<int> Q;
   Q.push(1);
   vis[1] = 1;
   while (!Q.empty())
   {
      int node = Q.front();
      Q.pop();
      cout << node << endl;

      /* vector<int> :: iterator it;
      for (it = adj[node].begin(); it != adj[node].end(); it++)
      {
          if(!vis[*it]){
              vis[*it]=1;
              Q.push(*it);
          }
      }
       */

      for (auto neighbor : adj[node])
      {
         if (!vis[neighbor])
         {
            vis[neighbor] = 1;
            Q.push(neighbor);
         }
      }
   }
}