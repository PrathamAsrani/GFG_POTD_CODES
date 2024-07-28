//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

typedef long long ll;

class Solution {
  public:
    ll total, mod = 1e9+7;
    ll helper(int i, int sum, vector<int> &arr, int &target, vector<vector<int>> &dp){
        if(i == arr.size()) return sum == target;
        if(dp[i][sum+total] != -1) return dp[i][sum+total];
        dp[i][sum+total] = (helper(i+1, sum-arr[i], arr, target, dp)%mod + helper(i+1, sum+arr[i], arr, target, dp)%mod)%mod;
    }
    ll findTargetSumWays(int n, vector<int>& arr, int target) {
        total = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2*total+1, -1));
        return helper(0, 0, arr, target, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends