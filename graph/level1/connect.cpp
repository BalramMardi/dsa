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

void getcomp(vector<vector<Edge>> &graph,vector<bool>&visited,int src,vector<int>&comp)
{
   visited[src]=true;
   comp.push_back(src);
   for (auto it : graph[src])
   {
     if(!visited[it.nbr])
     {
        getcomp(graph,visited,it.nbr,comp);
     }
   }
   
   
}
int main()
{
 int n,m;
 cin >> n >> m;
 vector<vector<Edge>> graph(n);
 
 for (int i = 0; i < m; i++)
 {
    int x,y,w;
    cin >> x >> y >>w;
    graph[x].push_back(Edge(x,y));
    graph[y].push_back(Edge(y,x));

 }
 

 vector<bool> visited(n,false);
 vector<vector<int>>comps;

 for (int i = 0; i < n; i++)
 {
    if(!visited[i])
    {
        vector<int> comp;
        getcomp(graph,visited,i,comp);
        comps.push_back(comp);
    }
 }
 
  for (int i = 0; i < comps.size(); i++)
 {
    for (int j = 0; j < comps[i].size(); j++)
    {
        cout << comps[i][j] << " ";
    }
    cout<< endl;
 } 
/*  cout << "[";
  for (int i = 0 ; i < comps.size() ; i++) {
    cout << "[";
    for (int j = 0 ; j < comps[i].size() ; j++) {
      if (j != comps[i].size() - 1)
        cout << comps[i][j] << ", ";
      else
        cout << comps[i][j];

    }
    cout << "]";
    if (i != comps.size() - 1)cout << ", ";
  }
  cout << "]"<<endl;
  */
 


 
 
 
}