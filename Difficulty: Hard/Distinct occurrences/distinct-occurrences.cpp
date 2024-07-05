//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    int n, m, mod = 1e9+7;
    vector<vector<int>> dp;
    public:
    int TD(int i, int j, string &s, string &t){
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) 
            return dp[i][j] = (TD(i+1, j+1, s, t) + TD(i+1, j, s, t))%mod;
        else 
            return dp[i][j] = TD(i+1, j, s, t);
    }
    int subsequenceCount(string s, string t)
    {
        n = s.size(), m = t.size();
        /
        dp.resize(n, vector<int>(m, -1));
        return TD(0, 0, s, t);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends