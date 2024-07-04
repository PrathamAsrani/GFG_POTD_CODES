//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int n, m;
    int LCS(string &s, string &t){
        vector<int> dp(m+1, 0);
        for(int i = 1; i <= n; i++){
            vector<int> curr(m+1, 0);
            for(int j = 1; j <= m; j++){
                int val = 0;
                if(s[i-1] == t[j-1]){
                    val = 1 + dp[j-1];
                }else{
                    val = max(dp[j], curr[j-1]);
                }
                curr[j] = val;
            }
            dp = curr;
        }
        return dp[m];
    }
	int minOperations(string s, string t) 
	{
	    n = s.size(), m = t.size();
        return n+m-(2*LCS(s, t));
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends