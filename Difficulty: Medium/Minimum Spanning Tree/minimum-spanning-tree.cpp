//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
    public:
        vector<int> parent, rank;
        DSU(int n){
            for(int i = 0; i < n; parent.push_back(i++));
            rank.resize(n, 0);
        }
        int Find(int node){
            return node == parent[node] ? node : parent[node] = Find(parent[node]);
        }
        void Unite(int a, int b){
            int p1 = Find(a), p2 = Find(b);
            if(p1 == p2) return ;
            int r1 = rank[p1], r2 = rank[p2];
            if(r1 > r2) parent[p2] = p1;
            else if(r1 < r2) parent[p1] = p2;
            else{
                parent[p2] = p1;
                rank[p1]++;
            }
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	void Kriskal_MST(int n, int &total, vector<vector<int>> &cost, vector<vector<int>> &ans){
	    vector<vector<int>> edges;
	    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(cost[i][j] != INT_MAX) edges.push_back({cost[i][j], i, j});
	    sort(edges.begin(), edges.end());
	    DSU dsu(n);
	    for(auto edge: edges){
	        int u = edge[1], v = edge[2], wei = edge[0];
	        int p1 = dsu.Find(u), p2 = dsu.Find(v);
	        if(p1 != p2){
	            dsu.Unite(p1, p2);
	            total += wei;
	            ans.push_back({u, v, wei});
	        }
	    }
	}
	
	void primsMST(int V, int &total, vector<vector<int>> &cost, vector<vector<int>> &ans){
	    int k = 0, l = 0, mini = INT_MAX;
	    for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) if(mini > cost[i][j]) k = i, l = j, mini = cost[i][j];
        ans.push_back({k, l, mini});
        total += mini;
        vector<int> near(V, INT_MAX);
        near[k] = near[l] = -1;
        for(int i = 0; i < V; i++){
            if(near[i] != -1){
                if(cost[k][i] < cost[l][i]) near[i] = k;
                else near[i] = l;
            }
        }
        for(int i = 0; i < V-2; i++){
            int minIdx, minVal = INT_MAX;
            for(int j = 0; j < V; j++){
                if(near[j] != -1 and cost[j][near[j]] < minVal){
                    minVal = cost[j][near[j]];
                    minIdx = j;
                }
            }
            ans.push_back({minIdx, near[minIdx], minVal});
            total += minVal;
            for(int j = 0; j < V; j++){
                if(near[j] != -1){
                    if(cost[j][minIdx] < cost[j][near[j]]){
                        near[j] = minIdx;
                    }
                }
            }
            near[minIdx] = -1;
        }
	}
	
	void Prims(int V, int &total, vector<vector<int>> adj[], vector<vector<int>> &ans){
	    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
	    vector<bool> vis(V, false);
	    minHeap.push({0, 0}); // {wei, node};
	    while(!minHeap.empty()){
	        auto itr = minHeap.top(); minHeap.pop();
	        int node = itr.second;
	        int wei = itr.first;
	        if(vis[node]) continue;
	        vis[node] = true;
	        total += wei;
	        for(auto nei: adj[node]){
	            int neig = nei[0], neig_wei = nei[1];
	            if(!vis[neig]){
	                minHeap.push({neig_wei, neig});
	            }
	        }
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int total = 0;
        vector<vector<int>> cost(V, vector<int>(V, INT_MAX));
        for(int u = 0; u < V; u++){
            for(auto nei: adj[u]){
                int v = nei[0], wei = nei[1];
                cost[u][v] = wei;
                cost[v][u] = wei;
            }
        }
        vector<vector<int>> ans;
        // primsMST(V, total, cost, ans);
        Prims(V, total, adj, ans);
        // Kriskal_MST(V, total, cost, ans);
        return total;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends