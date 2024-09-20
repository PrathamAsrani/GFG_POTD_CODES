//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.size(), mod = 1e9+7;
	    int dp[n+1]; fill_n(dp, n+1, 0);
	    dp[0] = 1;
	    unordered_map<char, int> umpp;
	    for(int i = 1; i <= n; i++){
	        dp[i] = (2 * dp[i-1])%mod;
	        if(umpp.find(s[i-1]) != umpp.end()){
	            int idx = umpp[s[i-1]];
	            dp[i] = (dp[i] - dp[idx] + mod)%mod;
	        }
	        umpp[s[i-1]] = i-1;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends