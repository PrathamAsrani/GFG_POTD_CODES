//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int> dis(N, INT_MAX);
        vector<pair<int, int>> adj[N];
        for(auto edge: edges) adj[edge[0]].push_back({edge[1], edge[2]});
        queue<pair<int, int>> q;
        q.push({0, 0}); // {dis, src}
        dis[0] = 0;
        while(!q.empty()){
            int dist = q.front().first;
            int node = q.front().second;
            q.pop();
            for(pair<int, int> nei: adj[node]){
                int neig = nei.first;
                int neiDist = nei.second;
                if(dist+neiDist < dis[neig]){
                    dis[neig] = dist+neiDist;
                    q.push({dis[neig], neig});
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends