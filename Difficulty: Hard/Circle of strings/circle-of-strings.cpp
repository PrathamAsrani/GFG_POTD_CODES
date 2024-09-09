//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int node, vector<int> adj[], vector<bool> &vis){
        vis[node] = 1;
        for(int nei: adj[node]){
            if(!vis[nei]){
                dfs(nei, adj, vis);
            }
        }
    }
  public:
    int isCircle(vector<string> &arr) {
        // code here
        vector<int> adj[26];
        vector<bool> vis(26, 0);
        int start = 0;
        for(auto &s: arr){
            int u = s[0] - 'a', v = s[s.size()-1] - 'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
            start = u;
        }
        dfs(start, adj, vis);
        for(int i = 0; i < 26; i++){
            if((!vis[i] && adj[i].size() > 0) || (adj[i].size()&1)){
                // multiple chains
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends