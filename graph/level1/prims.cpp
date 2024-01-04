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
    int psf=0;
    int src=0;
    int wt=0;
    Pair(int src,int psf,int wt){
        this->src =src;
        this->psf=psf;
        this->wt=wt;

    }
};

class Compare{
    public:
    bool operator()(const Pair &a,const Pair &b){
        /* if(a.wt==b.wt){
            return a.psf.length()<b.psf.length();
        }  */
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
 int src=0;
 
 vector<bool> visited(n,false);
  priority_queue<Pair,vector<Pair>,Compare> pq;
   
   
   pq.push(Pair(src,-1,0));
   while (!pq.empty())
   {
    /* code */
    Pair rem = pq.top();
    pq.pop();
    if(visited[rem.src] != 0)
    {
        continue;
    }
    visited[rem.src]=rem.psf;
    if(rem.psf != -1)
    {
        cout<< rem.src << " "<< rem.psf << " @ " << rem.wt<<endl;
    }

    
    for (auto it : graph[rem.src])
    {
        if(visited[it.nbr]==0){
            
            pq.push(Pair(it.nbr,rem.src,it.wt));
        }
    }
    

   }

    
}