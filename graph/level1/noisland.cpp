#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void countIsland(vector<vector<int>> &arr,vector<vector<bool>> &visited,int i,int j){
    if(i<0 or j<0 or i>=arr.size() or j>=arr[0].size() or arr[i][j]==1 or visited[i][j]==true)
    {

        return;
    }
        visited[i][j]=true;
        countIsland(arr,visited,i-1,j);
        countIsland(arr,visited,i,j+1);
        countIsland(arr,visited,i,j-1);
        countIsland(arr,visited,i+1,j);

    

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
 
 int count=0;
 for (int i = 0; i < n; i++)
 {
   for (int j = 0; j < m; j++)
   {
    if (arr[i][j] == 0 && visited[i][j] == false){
        countIsland(arr,visited,i,j);
        count++;

    }
      
   }
   
 }
 

cout << count;
}