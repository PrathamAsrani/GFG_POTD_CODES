//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int idx, int k, int n, vector<int> &arr, int dp[]){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int cost = INT_MAX;
        for(int i = idx+1; i <= idx+k && i < n; i++){
            int val = fun(i, k, n, arr, dp) + abs(arr[i] - arr[idx]);
            cost = min(cost, val);
        }
        return dp[idx] = cost == INT_MAX ? 0 : cost;
    }
    int minimizeCost(vector<int>& arr, int n, int k) {
        int dp[n];
        for(int i = 0; i < n; i++)
            dp[i] = 1e9;
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= k; j++){
                if(i-j >= 0){
                    dp[i] = min(dp[i], dp[i-j] + abs(arr[i] - arr[i-j]));
                }
            }
        }
        return dp[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends