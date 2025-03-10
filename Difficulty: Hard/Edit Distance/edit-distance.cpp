//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int n, m;
    vector<vector<int>> dp;
    int helper(string &s, string &t, int i = 0, int j = 0){
        if(i == n) return m-j;
        else if(j == m) return n-i;
        else if(dp[i][j] != -1) return dp[i][j];
        
        int val = 0;
        if(s[i] == t[j]){
            val = helper(s, t, i+1, j+1);
        }
        else {
            val = 1 + min({
                helper(s, t, i+1, j),
                helper(s, t, i, j+1),
                helper(s, t, i+1, j+1)
            });
        }
        return dp[i][j] = val;
    }
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        n = s1.size(), m = s2.size();
        // dp.resize(n, vector<int>(m, -1));
        // return helper(s1, s2);
        
        dp.resize(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++){
            dp[i][m] = n-i;
        }
        for(int j = 0; j <= m; j++){
            dp[n][j] = m-j;
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int val = 0;
                if(s1[i] == s2[j]){
                    val = dp[i+1][j+1];
                }
                else {
                    val = 1 + min({
                        dp[i+1][j],
                        dp[i][j+1],
                        dp[i+1][j+1]
                    });
                }
                dp[i][j] = val;
            }
        }
        return dp[0][0];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends