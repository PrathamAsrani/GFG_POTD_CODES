//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int *dp;
    int fun(vector<int> &arr, int idx, int &k, int &n){
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int mx = -1e9, ans = 0;
        for(int i = idx; i < min(n, idx + k); i++){
            if(mx < arr[i]) mx = arr[i];
            ans = max(ans, mx*(i-idx+1) + fun(arr, i+1, k, n));
        }
        return dp[idx] = ans;
    }
    public:
    int solve(int n, int k, vector<int>& arr){
        // Code here
        dp = new int[n];
        for(int i = 0; i < n; i++) dp[i] = -1;
        return fun(arr, 0, k, n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends