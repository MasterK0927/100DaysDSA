#include <bits/stdc++.h>
using namespace std;

/*
Assume the starting node to be the 1st node.
Initialise a queue for the BFS, as it gives FIFO.
Keep track of the visited nodes using visited array.
Reduce further computations by checking if element exists in queue or not.
*/

vector<int> bfs(vector<int> adj[], vector<int>& visited) {
    // Initializing a queue
    queue<int> q;
    vector<int> an;

    // Start BFS from node 0
    visited[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        an.push_back(curr);

        // Traverse all adjacent nodes
        for (int i = 0; i < adj[curr].size(); i++) {
            int neighbor = adj[curr][i];
            if (!visited[neighbor]) {
                 visited[neighbor] = 1; 
                q.push(neighbor);
               // Mark as visited when pushed into the queue
            }
        }
    }
    return an;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize adjacency list with size n
    vector<int> adj[n+1];

    // Filling the neighbors
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n, 0);
    vector<int> ans = bfs(adj, visited);

    // Print the result of BFS traversal
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i]+1 << " ";
    }

    return 0;
}
