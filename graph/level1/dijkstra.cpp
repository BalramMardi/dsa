#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int nbr=0;
    int src=0;
    int wt=0;
    Edge(int src,int nbr,int wt){
        this->src =src;
        this->nbr=nbr;
        this->wt=wt;
    }
};
class Pair{
    public:
    string psf="";
    int src=0;
    int wt=0;
    Pair(int src,string psf,int wt){
        this->src =src;
        this->psf=psf;
        this->wt=wt;

    }
};
//chalo kuch naya sikh liya jay...
class Compare{
    public:
    bool operator()(const Pair &a,const Pair &b){
        if(a.wt==b.wt){
            return a.psf.length()<b.psf.length();
        } 
        return a.wt>b.wt;
    }
};


int main()
{
 int n,m;
 cin >> n >> m;
 vector<vector<Edge>> graph(n);
 for (int i = 0; i < m; i++)
 {
    int x,y,w;
    cin >> x >> y >> w ;
    graph[x].push_back(Edge(x,y,w));
    graph[y].push_back(Edge(y,x,w));

 }
 int src;
 cin >>src;
 vector<bool> visited(n,false);
  priority_queue<Pair,vector<Pair>,Compare> pq;
   
   
   pq.push(Pair(src,to_string(src)+"",0));
   while (!pq.empty())
   {
    /* code */
    Pair rem = pq.top();
    pq.pop();
    if(visited[rem.src])
    {
        continue;
    }
    visited[rem.src]=true;
    cout<< rem.src << " "<< rem.psf << " @ " << rem.wt<<endl;
    for (auto it : graph[rem.src])
    {
        if(!visited[it.nbr]){
            
            pq.push(Pair(it.nbr,(rem.psf+to_string(it.nbr)),it.wt+rem.wt));
        }
    }
    

   }

    
}