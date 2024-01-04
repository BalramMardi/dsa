#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n,m;
 int x,y;
 
 cin >> n >> m;
 int cnt=0;
 vector<vector<int>>adj(n);
 vector<int> indeg(n,0);



 
 for (int i = 0; i < m; i++)
 {
    cin >> x >>y;
    adj[x].push_back(y);
    indeg[y]++;
    

 }

 queue<int> pq;
 for (int i = 0; i < n; i++)
 {
    if(indeg[i]==0){
        pq.push(i);
    }
 }
 while (!pq.empty())
 {
    /* code */
    cnt++;
    int z = pq.front();
    pq.pop();
    cout << z << " ";

    for (auto it : adj[z])
    {
        /* code */
        indeg[it]--;
        if(indeg[it]==0)
            pq.push(it);
    }
    
 }
 
 
 
 

 
 
}