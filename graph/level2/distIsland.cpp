#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> arr,int row,int col){

    if(row-1>0 and arr[row-1][col]==1){

    }
}


int main()
{
    int n,m;
 cin >> n >> m;
 vector<vector<int>> arr(n,vector<int>(m));
 vector<vector<bool>> visited(n,vector<bool>(m,false));

 for (int i = 0; i < n; i++)
 {
    for (int j = 0; j < m; j++)
    {
      cin >>arr[i][j];
       
    }
    
    
 }

 set<string> hashSet;

 for (int i = 0; i < n; i++)
 {
   for (int j = 0; j < m; j++)
   {
    if (arr[i][j] == 1){
        string str;
        str.append("x");
        dfs(arr,i,j);
        hashSet.insert(str.to_string());

    }
      
   }
   
 }
 
 
}