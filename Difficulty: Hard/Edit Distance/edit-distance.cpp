//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<vector<int>> dp;
    int n, m;
    int fun(int i, int j, string &s, string &t){
        if(i == n) return m-j;
        if(j == m) return n-i;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;
        if(s[i] == t[j]){
            ans = fun(i+1, j+1, s, t);
        } else {
            ans = min({
                fun(i+1, j, s, t), // delete i
                fun(i, j+1, s, t), // insert 
                fun(i+1, j+1, s, t) // replace
            }) + 1;
        }
        return dp[i][j] = ans;
    }
  public:
    int editDistance(string s, string t) {
        // Code here
        n = s.size(), m = t.size();
        
        /*
        dp.assign(n, vector<int>(m, -1));
        return fun(0, 0, s, t);
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