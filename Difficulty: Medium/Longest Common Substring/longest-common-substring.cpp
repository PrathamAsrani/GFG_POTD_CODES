//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int longestCommonSubstr(string &s, string &t, int n, int m)
    {
        /*
        // my way
        vector<string> arr;
        for(int i = 0; i < n; i++){
            string tmp;
            int idx = 0;
            for(int j = i; j < n; j++){
                tmp.push_back(s[j]);
                arr.push_back(tmp);
            }
        }
        int ans = 0;
        for(auto &str: arr){
            if(t.find(str) != string::npos){
                ans = max(ans, (int)str.size());
            }
        }
        return ans;
        */
        
        int ans = 0;
        int dp[n+1][m+1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = 0;
                
                if(dp[i][j] > ans)
                    ans = dp[i][j];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends