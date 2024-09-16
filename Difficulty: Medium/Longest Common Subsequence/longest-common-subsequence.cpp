//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s, string t) {
        vector<int> dp(m+1, 0);
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(m+1, 0);
            for(int j = m-1; j >= 0; j--){
                int ans = 0;
                if(s[i] == t[j]){
                    ans = dp[j+1] + 1;
                } else  {
                    ans = max(dp[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            dp = curr;
        }
        return dp[0];
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends