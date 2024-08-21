//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
typedef pair<int, int> pii;
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> dis(N, INT_MAX);
        vector<int> adj[N];
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dis[src] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            int cost = pq.top().first, node = pq.top().second;
            pq.pop();
            for(int nei: adj[node]){
                if(dis[nei] > cost+1){
                    dis[nei] = cost+1;
                    pq.push({dis[nei], nei});
                }
            }
        }
        for(auto &d: dis) if(d == INT_MAX) d = -1;
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends