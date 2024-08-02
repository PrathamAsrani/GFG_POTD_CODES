//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        if(n == 1) return {arr[0]};
        vector<int> lis;
        
        vector<int> dp(n, 1), pred(n, -1);
        dp[0] = 1;
        int idx = -1, len = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i] && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    pred[i] = j;
                }
            }
            if(len < dp[i]){
                len = dp[i];
                idx = i;
            }
        }
        
        while(idx != -1){
            lis.push_back(arr[idx]);
            idx = pred[idx];
        }
        
        reverse(lis.begin(), lis.end());
        
        return lis;
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
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends