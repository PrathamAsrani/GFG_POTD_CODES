//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, string &ans){
    vis[node] = true;
    for(int nei: adj[node]){
        if(!vis[nei]) dfs(nei, adj, vis, ans);
    }
    ans = char(node + 'a')+ans;
}

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        string ans = "";
        vector<vector<int>> adj(K, vector<int>(0));
        for(int i = 0; i < N-1; i++){
            string a = dict[i];
            string b = dict[i+1];
            int j = 0, mn = min(a.size(), b.size());
            while(j < mn){
                if(a[j] != b[j]){
                    adj[a[j] - 'a'].push_back(b[j] - 'a');
                    break;
                }
                j++;
            }
        }
        vector<bool> vis(K, false);
        for(int i = 0; i < K; i++){
            if(!vis[i]) dfs(i, adj, vis, ans);
        }
        return ans;
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