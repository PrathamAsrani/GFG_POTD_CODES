//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
    vector<vector<int>> dp;
    int fun(string &s, int i, int j){
        if(i > j)
            return 0;
        else if(dp[i][j] != -1)
            return dp[i][j];
            
        if(s[i] == s[j]){
            return dp[i][j] = (i == j) ? 1 + fun(s, i+1, j-1) : 2 + fun(s, i+1, j-1);
        }
        else {
            return dp[i][j] = max(fun(s, i+1, j), fun(s, i, j-1));
        }
    }
  public:
    int longestPalinSubseq(string &s) {
        // code here
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return fun(s, 0, s.size()-1);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends