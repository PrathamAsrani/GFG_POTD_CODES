//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long ll;

class Solution {
  public:
    int mod = 1e9+7;
    ll total = 0;
    vector<vector<ll>> dp;
    ll helper(int idx, ll sum, int n, int d, vector<int> &arr){
        if(idx == n){
            return total-sum >= sum && total-2*sum == d;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        ll take = helper(idx+1, sum + arr[idx], n, d, arr);
        ll notTake = helper(idx+1, sum, n, d, arr);
        
        return dp[idx][sum] = (take+notTake)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        /*
        this->total = accumulate(arr.begin(), arr.end(), 0);
        this->dp.resize(n, vector<ll>(total+1, -1));
        return helper(0, 0LL, n, d, arr);
        */
        
        /*
        ll total = accumulate(arr.begin(), arr.end(), 0);
        ll diff = total - d;
        if(diff&1 || diff < 0) return 0;
        ll target = diff/2;
        vector<vector<ll>> dp(n+1, vector<ll>(target+1, 0));
        int mod = 1e9+7;
        
        for(int i = 0; i <= n; i++) dp[i][0] = 1; // base case : target == 0
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(j >= arr[i-1]) take = dp[i-1][j-arr[i-1]];
                dp[i][j] = (take+notTake)%mod;
            }
        }
        return dp[n][target];
        */
        
        
        ll total = accumulate(arr.begin(), arr.end(), 0);
        ll diff = total - d;
        if(diff&1 || diff < 0) return 0;
        ll target = diff/2;
        vector<ll> dp(target+1, 0);
        int mod = 1e9+7;
        
        dp[0] = 1; // base case : target == 0
        for(int i = 1; i <= n; i++){
            vector<ll> curr(target+1, 0);
            curr[0] = 1;
            for(int j = 0; j <= target; j++){
                int notTake = dp[j];
                int take = 0;
                if(j >= arr[i-1]) take = dp[j-arr[i-1]];
                curr[j] = (take+notTake)%mod;
            }
            dp = curr;
        }
        return dp[target];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends