//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int node, vector<int> adj[], vector<bool> &vis, string &order){
        vis[node] = true;
        for(int &nei: adj[node]){
            if(!vis[nei]){
                dfs(nei, adj, vis, order);
            }
        }
        order = char(node + 'a') + order;
    }
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<int> adj[k];
        for(int i = 0; i+1 < n; i++){
            string a = dict[i];
            string b = dict[i+1];
            int len = min(a.size(), b.size());
            for(int j = 0; j < len; j++){
                if(a[j] != b[j]){
                    adj[a[j] - 'a'].push_back(b[j] - 'a');
                    break;
                }
            }
        }
        vector<bool> vis(k, 0);
        string order;
        for(int i = 0; i < k; i++){
            if(!vis[i]){
                dfs(i, adj, vis, order);
            }
        }
        return order;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends