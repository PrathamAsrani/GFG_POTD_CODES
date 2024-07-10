//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int n, m;
    vector<vector<int>> dp;
  public:
    int f(string &s, string &t, int i = 0, int j = 0) {
        if(i == n) return m-j;
        if(j == m) return n-i;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = f(s, t, i+1, j+1);
        else{
            return dp[i][j] = min({
                f(s, t, i, j+1),
                f(s, t, i+1, j),
                f(s, t, i+1, j+1)
            }) + 1;
        }
    }
    int editDistance(string s, string t) {
        n = s.size(), m = t.size();
        dp.resize(n, vector<int>(m, -1));
        return f(s, t);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends