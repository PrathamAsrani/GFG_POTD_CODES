//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int n;
    vector<vector<vector<int>>> dp;
    int fun(int arr[], int i, int trans, bool buy){
        if(i == n || trans == 0) return 0;
        if(dp[i][trans][buy] != -1) return dp[i][trans][buy];

        int val = fun(arr, i+1, trans, buy);
        if(buy){
            val = max(val, fun(arr, i+1, trans, !buy) - arr[i]);
        } else {
            val = max(val, fun(arr, i+1, trans-1, !buy) + arr[i]);
        }
        return dp[i][trans][buy] = val;
    }
  public:
    int maxProfit(int k, int n, int arr[]) {
        // code here
        this->n = n;
        dp.resize(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return fun(arr, 0, k, true);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends