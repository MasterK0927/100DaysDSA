/*
In c++, a graph can be stored using a list (which here is vector) also.
It reduces the SC to O(2*E).
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    //filling the neighbours of each node.
    for (int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //commenting this line will give code for directed graph
    }
    //printing the graph;
    for(int i=0; i<n+1; i++){
        int size = adj[i].size();
        for(int j=0; j<size; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}