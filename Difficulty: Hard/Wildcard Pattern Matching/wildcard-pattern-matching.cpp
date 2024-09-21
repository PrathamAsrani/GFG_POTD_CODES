//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int n, m;
    vector<vector<int>> dp;
    int fun(int i, int j, string &s, string &p){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == n && j == m) return 1;
        if(i == n && j < m && p[j] == '*') 
            return fun(i, j+1, s, p);
        if(i == n || j == m) return 0;
        
        bool ans = 0;
        if(p[j] == '*') 
            ans = fun(i+1, j, s, p) || fun(i, j+1, s, p);
        else if(s[i] == p[j] || p[j] == '?')
            ans = fun(i+1, j+1, s, p);
        
        return dp[i][j] = ans;
    }
  public:
    /*You are required to complete this method*/
    int wildCard(string p, string s) {
        // code here
        n = s.size(), m = p.size();
        /*
        dp.assign(n+1, vector<int>(m+1, -1));
        return fun(0, 0, s, p);
        */
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