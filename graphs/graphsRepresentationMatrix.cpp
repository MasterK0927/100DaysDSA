//there are two ways of representing graphs in c++, one using adjacency list
//other using adjacency matrix
//SC: O(n^2);

//Using Matrix;

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n+1, vector<int>((n+1),0));
    //storing the edges as true i.e. 1
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1; //commenting this line give code for directed graph
    }
    //printing the graph
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}