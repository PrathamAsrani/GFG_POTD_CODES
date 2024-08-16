//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1] = {-1};
        dp[0] = 0;
        for(int len = 1; len <= n; len++){
            int cuts = -1;
            if(x <= len && dp[len-x] != -1) cuts = max(cuts, dp[len-x]+1);
            if(y <= len && dp[len-y] != -1) cuts = max(cuts, dp[len-y]+1);
            if(z <= len && dp[len-z] != -1) cuts = max(cuts, dp[len-z]+1);
            dp[len] = cuts;
        }
        return max(0, dp[n]);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends