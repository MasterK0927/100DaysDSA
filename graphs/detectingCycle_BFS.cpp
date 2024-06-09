#include <bits/stdc++.h>
using namespace std;

bool isCycleBFS(vector<int>adj[],vector<bool>& visited, int src, int parent){
    queue<pair<int,int>>q;
    q.push({src,parent});
    vis[src]=true;
    while(!q.empty()){
        int node = q.front().first;
        int prnt = q.front().second;
        q.pop();
        for(auto& adjNode:adj[node]){
            if(!visited[i]){
                q.push({adjNode,node});
            }
            else if(prnt!=src){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<int>adj[],int n; int m){
    vector<bool>visited(n,true);
    for(int i=0; i<n; i++){
        if(!visited[i] && isCycleBFS(adj,visited,i,-1)) return true;
    }
    return false;
}

int main(){
    vector<vector<int>> grid = {
        {1,1},
        {0,1},
        {1,0}
    };
    int n = grid.size();
    int m = grid[0].size();
    vector<int> adj[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            adj[j].push_back(i);
            adj[i].push_back(j);
        }
    }
    if(isCycle(adj,n,m)) cout<<1;
    cout<<0;
    return 0;
}