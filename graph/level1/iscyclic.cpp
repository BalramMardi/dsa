#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int nbr=0;
    int src=0;
    Edge(int src,int nbr){
        this->src =src;
        this->nbr=nbr;
    }
};
class Pair{
    public:
    string psf="";
    int src=0;
    Pair(int src,string psf){
        this->src =src;
        this->psf=psf;
    }
};

bool isCyclic(vector<vector<Edge>> &graph,vector<bool>&visited,int src)
{
   queue<Pair> q;
   q.push(Pair(src,src+""));
   while (!q.empty())
   {
    /* code */
    Pair rem = q.front();
    q.pop();
    if(visited[rem.src])
    {
        return true;
    }
    visited[rem.src]=true;
    for (auto it : graph[rem.src])
    {
        if(!visited[it.nbr]){
            
            q.push(Pair(it.nbr,(rem.psf+to_string(it.nbr))));
        }
    }
    

   }
   return false;
   
}
int main()
{
 int n,m;
 cin >> n >> m;
 vector<vector<Edge>> graph(n);
 for (int i = 0; i < m; i++)
 {
    int x,y;
    cin >> x >> y ;
    graph[x].push_back(Edge(x,y));
    graph[y].push_back(Edge(y,x));

 }
 
 vector<bool> visited(n,false);

 for (int i = 0; i < n; i++)
 {
    if(!visited[i]){
        bool flag = isCyclic(graph,visited,i);
        if(flag)
        {
            cout << "true";
            return 0;
        }
        
    }
 }
 
 cout << "false";
 

 
 
 
}