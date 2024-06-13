//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
        int m = 1e9+7;
        int dp[max(3, n+1)]; 
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; dp[i] = (dp[i-2] + dp[i-3])%m, i++);
        return dp[n];
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends