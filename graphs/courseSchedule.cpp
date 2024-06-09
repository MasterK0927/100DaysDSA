class Solution {
private:
    bool dfs(vector<int>adj[], vector<int>& adj, int src){
        visited[src]={1,1};
        for(auto& it:adj[src]){
            if(!visited[it].first && dfs(sdj,visited,it)) return true;
            else if(visited[it].second) return true;
        }
        visited[src]={1,0};
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto& it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<pair<int,int>> visited(numCourses,{0,0});
        for(int i=0; i<numCourses; i++){
            if(!visited[i].first && dfs(adj,visited,i)) return false;
        }
        return true;
    }
};