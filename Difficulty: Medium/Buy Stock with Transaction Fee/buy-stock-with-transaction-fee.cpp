//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    typedef long long ll;
    int n, fee;
    vector<vector<ll>> dp;
    
    ll fun(vector<ll> &arr, int i, bool buy){
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        
        ll val = fun(arr, i+1, buy);
        if(buy){
            val = max(val, fun(arr, i+1, !buy) - arr[i]);
        } else {
            val = max(val, fun(arr, i+1, !buy) + arr[i] - fee);
        }
        return dp[i][buy] = val;
    }
    
    public:
    long long maximumProfit(vector<long long>&arr, int n, int fee) {
        // Code here
        this->n = n, this->fee = fee;
        dp.resize(n, vector<ll>(2, -1));
        return fun(arr, 0, true);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends