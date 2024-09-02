//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int dp[1001][1001];
	int helper(string s, string t, int i = 0, int j = 0){
	    // case 1: if s is empty and t having chars then insert the remaining
	    if(i == s.size()) return t.size()-j;
	    // case 2: if s is having chars and t is empty then erase the remaining
	    if(j == t.size()) return s.size()-i;
	    if(dp[i][j] != -1) return dp[i][j];
	    
	    int ans = 1e9;
	    if(s[i] == t[j]){
	        ans = min(ans, helper(s, t, i+1, j+1));
	    } else {
	        // insert
	        ans = min(ans, helper(s, t, i+1, j)+1);
	        // delete
	        ans = min(ans, helper(s, t, i, j+1)+1);
	    }
	    return dp[i][j] = ans;
	}
	public:
	int minOperations(string s, string t) 
	{ 
	    // Your code goes here
	    /*
	    memset(dp, -1, sizeof(dp));
	    return helper(s, t);
	    */
	    
	    /*
	    int n = s.size(), m = t.size();
	    for(int i = n; i >= 0; i--){
	        for(int j = m; j >= 0; j--){
	            if(i == n) dp[i][j] = m-j;
	            else if(j == m) dp[i][j] = n-i;
	            else if(s[i] == t[j]) dp[i][j] = dp[i+1][j+1];
	            else dp[i][j] = min(1 + dp[i+1][j], 1 + dp[i][j+1]);
	        }
	    }
	    return dp[0][0];
	    */
	    
	    int n = s.size(), m = t.size();
	    vector<int> memo(m+1);
        for(int i = 0; i <= m; i++)
            memo[i] = m-i;
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(m+1);
            for(int j = m; j >= 0; j--){
                if(j == m) curr[j] = n-i;
                else if(s[i] == t[j]) curr[j] = memo[j+1];
                else curr[j] = min({1+memo[j], 1+curr[j+1]});
            }
            memo = curr;
        }
        return memo[0];
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