
/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of 
    vertices such that for every directed edge uv, vertex u comes before v in 
    the ordering. Topological Sorting for a graph is not possible if the graph 
    is not a DAG.

    Topological sort is not unique... There can be more than one sorts of 
    same graph

    Properties--->
        1---> Acyclic
        2---> Directed
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    int count = 0;      // To count the steps of topological order
    vector<vector<int>> adj(n);

    vector<int> indegree(n, 0);

    for(int i=0; i<m; i++){
        int x, y;
        cout<<"Enter the starting and ending vertices of edges: "<<endl;
        cin>>x>>y;

        // Directed
        adj[x].push_back(y);
        indegree[y]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    cout<<"Topological sort of the given graph is: "<<endl;
    while(!q.empty()){
        count++;
        int x = q.front();
        q.pop();
        cout<<x<<" ";

        vector<int> :: iterator it;
        for(it=adj[x].begin(); it!=adj[x].end(); it++){
            indegree[*it]--;
            if(indegree[*it] == 0){
                q.push(*it);
            }
        }
    }
    cout<<endl;

    if(count != n){
        cout<<"Graph is cyclic";
    }

    return 0;
}