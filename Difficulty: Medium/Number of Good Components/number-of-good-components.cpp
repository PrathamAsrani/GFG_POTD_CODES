//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
    vector<vector<int>> adj;
    vector<int> inDegree;
    vector<bool> vis;
    void dfs(int node, vector<int> &nodes){
        vis[node] = true;
        for(int nei: adj[node]){
            if(!vis[nei]){
                dfs(nei, nodes);
            }
        }
        nodes.push_back(node);
    }
    bool checkValid(int node){
        vector<int> nodes;
        dfs(node, nodes);
        for(int x: nodes){
            if(inDegree[x] != nodes.size()-1){
                return false;
            }
        }
        return true;
    }
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vis.resize(v, 0);
        adj.resize(v);
        inDegree.resize(v, 0);
        for(auto &edge: edges){
            int u = edge[0]-1, v = edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            inDegree[u]++;
            inDegree[v]++;
        }
        int cnt = 0;
        for(int i = 0; i < v; i++){
            if(!vis[i] && checkValid(i)){
                cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends