//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, int par, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis){
        vis[node] = pathVis[node] = true;
        for(int nei: adj[node]){
            if(nei != par && !vis[nei] && dfs(nei, node, adj, vis, pathVis)){
                return 1;
            } else if(nei != par && pathVis[nei]){
                return 1;
            }
        }
        pathVis[node] = false;
        return 0;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // by dfs
        vector<bool> vis(V, 0), pathVis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i] && dfs(i, -1, adj, vis, pathVis)) 
                return 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends