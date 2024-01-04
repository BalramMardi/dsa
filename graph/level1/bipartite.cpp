#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src;
    this->nbr = nbr;
  }
};

class Pair
{
public:
  int src = 0;
  string psf = "";
  int level=0;
  Pair(int src, string psf,int level)
  {
    this->src = src;
    this->psf = psf;
    this->level=level;

  }
};

bool isBipartite(vector<vector<Edge>>&graph,vector<int>&visited,int src){
    
  queue<Pair> q;
  q.push(Pair(src, to_string(src) + "",0));
  while (q.size() != 0) {

    Pair rem = q.front();
    q.pop();
    if (visited[rem.src] != -1) {
        if(visited[rem.src] != rem.level){
            return false;
        }
    }
    else{
        visited[rem.src] = rem.level;
    }
    for (auto it : graph[rem.src])
    {
        /* code */
        if(visited[it.nbr]==-1){
            q.push(Pair(it.nbr,rem.psf+to_string(it.nbr),rem.level+1));
        }
    }
    
    
    }

    return true;
  }


int main() {
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  //vector<Edge>graph[vtces]; can also be used

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));

  }
  

 vector<int> visited(vtces,-1);
 for (int i = 0; i < vtces; i++)
 {
    if (visited[i]==-1)
    {
        /* code */
        bool flag = isBipartite(graph,visited,i);
        if(flag==false){
            cout << "false";
            return 0;
        }
    }
    
 }
 
  
  cout <<"true";

}