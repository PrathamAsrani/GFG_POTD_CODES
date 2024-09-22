//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    vector<bool> vis;
    void getNodeInStack(int node, vector<vector<int>> &adj, stack<int> &st){
        vis[node] = 1;
        for(int nei: adj[node]){
            if(!vis[nei])
                getNodeInStack(nei, adj, st);
        }
        st.push(node);
    }
    void dfs(int node, vector<vector<int>> &adj){
        vis[node] = 1;
        for(int nei: adj[node]){
            if(!vis[nei])
                dfs(nei, adj);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vis.resize(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                getNodeInStack(i, adj, st);
            }
        }
        vector<vector<int>> adjT(V);
        for(int node = 0; node < V; node++){
            vis[node] = 0;
            for(int nei: adj[node]){
                adjT[nei].push_back(node);
            }
        }
        
        int cnt = 0;
        while(!st.empty()){
            if(!vis[st.top()]){
                dfs(st.top(), adjT);
                cnt++;
            }
            st.pop();
        }
        return cnt;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends