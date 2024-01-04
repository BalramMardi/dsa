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
  Pair(int src, string psf)
  {
    this->src = src;
    this->psf = psf;
  }
};



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
  int src;
  cin >> src;


  vector<bool> visited(vtces, false);
  queue<Pair> q;
  q.push(Pair(src, to_string(src) + ""));
  while (q.size() != 0) {

    Pair rem = q.front();
    q.pop();
    if (visited[rem.src] == true) {
      continue;
    }
    visited[rem.src] = true;
    cout << rem.src << "@" << rem.psf << endl;
    for (Edge e : graph[rem.src]) {
      if (visited[e.nbr] == false) {
        q.push(Pair(e.nbr, rem.psf + to_string(e.nbr)));
      }
    }
  }
  return 0;
}