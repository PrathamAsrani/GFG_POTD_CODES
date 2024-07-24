//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int helper(int i, int wei[], int val[], int w, int n, vector<vector<int>> &dp){
        if(i >= n) return 0;
        if(dp[i][w] != -1) return dp[i][w];
        int notTake = helper(i+1, wei, val, w, n, dp);
        int take = 0;
        if(w >= wei[i]) take = helper(i+1, wei, val, w-wei[i], n, dp) + val[i];
        return dp[i][w] = max(take, notTake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        /*
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return helper(0, wt, val, W, n, dp);
        */
        
        /*
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= W; j++){
                int take = 0, notTake = 0;
                notTake = dp[i-1][j];
                if(j >= wt[i-1]) take = dp[i-1][j-wt[i-1]] + val[i-1];
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n][W];
        */
        
        vector<int> dp(W+1, 0);
        for(int i = 0; i < n; i++){
            vector<int> curr(W+1, 0);
            for(int j = 0; j <= W; j++){
                int take = 0, notTake = 0;
                notTake = dp[j];
                if(j >= wt[i]) take = dp[j-wt[i]] + val[i];
                curr[j] = max(take, notTake);
            }
            dp = curr;
        }
        return dp[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends