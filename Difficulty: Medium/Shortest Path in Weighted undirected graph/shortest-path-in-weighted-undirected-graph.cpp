//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    typedef pair<int, int> pii;
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<pii>> adj(n, vector<pii>(0));
        for(auto &e: edges){
            int u = e[0]-1, v = e[1]-1, wei = e[2];
            adj[u].push_back({v, wei});
            adj[v].push_back({u, wei});
        }
        
        pq.push({0, 0});
        vector<int> dis(n, INT_MAX);
        vector<int> parent(n, -1);
        dis[0] = 0;
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int node = it.second, wei = it.first;
            for(auto &itr: adj[node]){
                int nei = itr.first, cost = itr.second;
                if(dis[nei] > wei+cost){
                    dis[nei] = wei+cost;
                    pq.push({dis[nei], nei});
                    parent[nei] = node;
                }
            }
        }
        
        if(dis[n-1] == INT_MAX) 
            return {-1};
        
        vector<int> path;
        for(int node = n-1; node != -1; node = parent[node]){
            path.push_back(node+1);
        }
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dis[n-1]);
        return path;
    }
};



//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends