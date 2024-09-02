//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int dp[1001][1001];
	int helper(string s, string t, int i = 0, int j = 0){
	    // case 1: if s is empty and t having chars then insert the remaining
	    if(i == s.size()) return t.size()-j;
	    // case 1: if s is having chars and t is empty then erase the remaining
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
	    memset(dp, -1, sizeof(dp));
	    return helper(s, t);
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