//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int LCS(string a, string b){
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i-1] == b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestPalinSubseq(string A) {
        /*
        // bottom up
        
        string B = A;
        reverse(B.begin(), B.end());
        return LCS(A, B);
        */
        
        /*
        string s = A;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int, int)> td = [&](int i, int j) -> int {
            if( i > j ) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            int val = 0;

            if(s[i] == s[j]){
                if(i == j) val = 1 + td(i+1, j-1);
                else val = 2 + td(i+1, j-1);
            }else{
                val = max(td(i+1, j), td(i, j-1));
            }

            return dp[i][j] = val;
        };
        return td(0, n-1);
        */
        
        
        string s = A;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n-1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i+1; j < n; j++){
                int val = 0;
                if(s[i] == s[j]){
                    val = 2 + dp[i+1][j-1];
                } else {
                    val = max(dp[i+1][j], dp[i][j-1]);
                }
                dp[i][j] = val;
            }
        }
        return dp[0][n-1];
    }
};


//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends