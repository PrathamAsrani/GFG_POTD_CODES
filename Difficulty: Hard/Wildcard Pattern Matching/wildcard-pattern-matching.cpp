//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int n, m;
    vector<vector<int>> dp;
    int f(string s, string p, int i = 0, int j = 0){
        // base case
        if(dp[i][j] != -1) return dp[i][j];
        if(i >= n and j >= m) return 1;
        if(i >= n and j < m and p[j] == '*') return f(s, p, i, j+1);
        if(i >= n || j >= m) return 0;
        
        // func-s call
        if(p[j] == '*') return dp[i][j] = f(s, p, i+1, j) || f(s, p, i, j+1);
        if(p[j] == '?' || s[i] == p[j]) return dp[i][j] = f(s, p, i+1, j+1);
        return dp[i][j] = 0;
    }
  public:
    /*You are required to complete this method*/
    int wildCard(string p, string s) {
        n = s.size(), m = p.size();
        
        dp.resize(n+1, vector<int>(m+1, -1));
        return f(s, p);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends