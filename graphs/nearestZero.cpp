#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>>& graph){
    //taking out the column and row sizes;
    int n = graph.size();
    int m = graph[0].size();
    //declaring the required variables;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dist(n, vector<int>(m,0));
    //declaring queue for storing the coords and the count;
    queue<pair<pair<int,int>,int>>q;
    //traversing throught the grid and checking for 1, if found, push it into the grid;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]==1){
                q.push({{i,j},0});
                //mark the node visited;
                vis[i][j]=1;
            }
            else{
                //if not then mark the node unvisited;
                vis[i][j]=0;
            }
        }
    }
    //declaring the traversingArray;
    int traversalArray[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
    //now traversing queue;
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int steps=q.front().second;
        //now pop that node out of the array;
        q.pop();
        //mark the steps in the dist array;
        dist[r][c]=steps;
        //traversing from that node;
        for(int i=0; i<4; i++){
            int nr=r+traversalArray[i][0];
            int nc=c+traversalArray[i][1];
            //checking the boundary cases;
            if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0){
                //marking the visited nodes as visited;
                vis[nr][nc]=1;
                //pushing the other nodes;
                q.push({{nr,nc},steps+1});
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>>graph = {
        {1,0,1},
        {1,1,0},
        {1,0,0},
    };
    vector<vector<int>> ans = nearest(graph);
    for(auto& i:ans){
        for(auto& j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}