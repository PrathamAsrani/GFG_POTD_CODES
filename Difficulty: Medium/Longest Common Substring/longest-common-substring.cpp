//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int n, m;
    int fun(int i, int j, string &s, string &t){
        if(i == n || j == m || s[i] != t[j])
            return 0;
        
        return 1 + fun(i+1, j+1, s, t);
    }
  public:
    int longestCommonSubstr(string s, string t) {
        // your code here
        /*
        n = s.size(), m = t.size();
        vector<string> arr;
        for(int i = 0; i < n; i++){
            string sub;
            for(int j = i; j < n; j++){
                sub += s[j];
                arr.push_back(sub);
            }
        }
        int ans = 0;
        for(string &sub: arr){
            if(t.find(sub) != string::npos){
                ans = max(ans, (int) sub.size());
            }
        }
        return ans;
        */
        
        /*
        n = s.size(), m = t.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, fun(i, j, s, t));
            }
        }
        return ans;
        */
        
        n = s.size(), m = t.size();
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends