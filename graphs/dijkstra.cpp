#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> p ;

void addEdge(vector<vector<p>>& graph, int u, int v, int w) {
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w)); // For undirected graph
}

vector<int> dijkstra(vector<vector<p>>& graph, int source, int V){
    //now using queue for storing all the stuff
    vector<int> result(V, INT_MAX);
    queue<p>q;
    q.push({0,source}); //{distance , node};
    result[source] = 0;

    while(!q.empty()){
        p curr = q.front();
        int d = curr.first; 
        int node = curr.second;
        q.pop();
        //neighbours of node
        for(auto& it:graph[node]){
            int nei = it.first;
            int dist = it.second;
            if(ans[nei] > ans[node] + dist) {
                ans[nei] = ans[node] + dist;
                q.push({ans[nei], nei});
            }
        }
    } 
    return ans;   
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<p>> graph(V);

    // Adding edges to the graph
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 1, 3);
    addEdge(graph, 2, 3, 9);
    addEdge(graph, 2, 4, 2);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 4, 0, 7);
    addEdge(graph, 4, 3, 6);

    // Running Dijkstra's algorithm from source vertex 0
    vector<int> ans = dijkstra(graph, 0, V);

    return 0;
}