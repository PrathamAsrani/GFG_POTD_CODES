//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = 1;
        for(int nei: adj[node]){
            if(!vis[nei]){
                dfs(nei, vis, adj);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> graph(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(i != j && adj[i][j] == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<bool> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, graph);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends