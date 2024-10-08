//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    typedef long long int lli;
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        int mod = 1e9+7;
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
                else if(j == 0) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
        }
        return dp[m-1][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends