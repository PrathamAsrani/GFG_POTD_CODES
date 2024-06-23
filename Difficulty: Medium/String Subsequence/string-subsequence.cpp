//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[501][501];
    int mod = 1e9+7;
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    int countWays(string s1, string s2, int i = 0, int j = 0) {
        /*
        if(j == s2.size()) return 1;
        if(i == s1.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int val = 0;
        if(s1[i] == s2[j]){
            val += countWays(s1, s2, i+1, j+1);
        }
        val += countWays(s1, s2, i+1, j);
        
        return dp[i][j] = val%mod;
        */
        
        /*
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // base case str1 is empty
        for(int i = 0; i <= m; i++) dp[0][i] = 0;
        // base case str2 is empty
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int val = 0;
                if(s1[i-1] == s2[j-1]){
                    val = (val + dp[i-1][j-1])%mod;
                }
                val = (val+dp[i-1][j])%mod;
                dp[i][j] = val;
            }
        }
        return dp[n][m];
        */
        
        int n = s1.size(), m = s2.size();
        vector<int> dp(m+1, -1);
        dp[0] = 1; // str2 == "" basecase
        for(int i = 1; i <= m; i++) dp[i] = 0; // str1 == "" basecase
        for(int i = 1; i <= n; i++){
            vector<int> curr(m+1, 0);
            curr[0] = 1;
            for(int j = 1; j <= m; j++){
                int val = 0;
                if(s1[i-1] == s2[j-1]){
                    val = (val + dp[j-1])%mod;
                }
                val = (val + dp[j])%mod;
                curr[j] = val;
            }
            dp = curr;
        }
        return dp[m];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends