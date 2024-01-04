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

bool hasPath(vector<vector<Edge>> &graph,vector<bool>&visited,int src,int des)
{
   if(src == des){
    return true;
   }
   visited[src]=true;
   for (auto it : graph[src])
   {
     if(visited[it.nbr]==false){
        hasPath(graph,visited,it.nbr,des);
        if(hasPath){
            return true;
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
    int x,y,w;
    cin >> x >> y >>w;
    graph[x].push_back(Edge(x,y));
    graph[y].push_back(Edge(y,x));

 }
 int src,des ;
 cin >> src >> des;

 vector<bool> visited(n,false);
 bool flag = hasPath(graph,visited,src,des);
 if(flag == true)
 cout << "Yes";
 else
 cout << "No";


 
 
 
}