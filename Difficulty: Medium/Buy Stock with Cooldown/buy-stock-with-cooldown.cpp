//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    vector<vector<long long>> dp;
    long long fun(vector<long long> &arr, int i, bool buy, int n){
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        long long val = fun(arr, i+1, buy, n);
        if(buy){
            val = max(val, fun(arr, i+1, !buy, n)-arr[i]);
        } else {
            val = max(val, fun(arr, i+2, !buy, n)+arr[i]);
        }
        return dp[i][buy] = val;
    }
    public:
    long long maximumProfit(vector<long long>&arr, int n) {
        // Code here
        dp.resize(n, vector<long long>(2, -1));
        return fun(arr, 0, true, n);
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
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends