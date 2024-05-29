/*
Instead of using queue, we will use stack.
LIFO technique of stack is being used.
Same visited array technique.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int>dfs(vector<int>adj[],vector<int>& visited){
    //ans array for storing ans;
    vector<int> arr;
    //stack initialisation
    stack<int> st;
    //initialising case of 0 as true;
    visited[0]=1;
    //pushing the initial node;
    st.push(0);

    while(!st.empty()){
        //take out the front value of stack and store it as curr
        int curr = st.top();
        //pop that value from stack
        st.pop();
        //push that value as answer to the answer array arr
        arr.push_back(curr);
        //now checking for its neighbor
        for(int i=0; i<adj[curr].size(); i++){
            //now we are iterating over the [[some,value]];
            int nei = adj[curr][i];
            //if "some" is not visited b4, store it in queue and mark it visitied
            if(!visited[nei]){
                //push the value of nei to stack
                st.push(nei);
                //mark it as visited
                visited[nei]=1;
            }
        }
    }
    //return the ans;
    return arr;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    //assigning neighbors
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        //converting it into zero based indexing
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //making the visited array
    vector<int>visited(n+1,0);
    //ans array for storing ans
    vector<int>ans=dfs(adj,visited);
    //printing output
    for(int i=0; i<ans.size(); i++){
        //compensating for zero based indexing
        cout<<ans[i]+1<<" ";
    }
    return 0;
}