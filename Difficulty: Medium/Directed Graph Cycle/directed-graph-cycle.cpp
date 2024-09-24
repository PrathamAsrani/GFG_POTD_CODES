//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis){
        vis[node] = pathVis[node] = true;
        for(int nei: adj[node]){
            if(!vis[nei] && dfs(nei, adj, vis, pathVis)){
                return 1;
            } else if(pathVis[nei]){
                return 1;
            }
        }
        pathVis[node] = false;
        return 0;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // by dfs
        vector<bool> vis(V, 0), pathVis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i] && dfs(i, adj, vis, pathVis)) 
                return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends