//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int dp[201][201];
    bool fun(string &a, string &b, int i, int j){
        if(i == a.size() && j == b.size()) return true;
        if(j == b.size() && a[i] == '*') return fun(a, b, i+1, j);
        if(i == a.size() || j == b.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == '*') return dp[i][j] = fun(a, b, i, j+1) || fun(a, b, i+1, j);
        if(a[i] == b[j] || a[i] == '?') return dp[i][j] = fun(a, b, i+1, j+1);
        return dp[i][j] = false;
    }
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        memset(dp, -1, sizeof(dp));
        return fun(pattern, str, 0, 0);
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