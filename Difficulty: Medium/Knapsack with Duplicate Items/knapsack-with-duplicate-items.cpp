//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i, int capa, int n, int val[], int wt[], vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][capa] != -1) return dp[i][capa];
        int notTake = helper(i+1, capa, n, val, wt, dp);
        int take = 0;
        if(capa >= wt[i]){
            take = helper(i, capa - wt[i], n, val, wt, dp) + val[i];
        }
        return dp[i][capa] = max(take, notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        /*
        // TC: O(N^2), SC: O(N^2) + O(N) -> Auxiliary space
        vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
        return helper(0, W, N, val, wt, dp);
        */
        
        
        /*
        // TC: O(N^2), SC: O(N^2)
        // O(N) -> Auxiliary space is optimized
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= W; j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(j >= wt[i-1]){
                    take = dp[i][j-wt[i-1]] + val[i-1];
                }
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[N][W];
        */
        
        vector<int> dp(W+1, 0);
        for(int i = 0; i < N; i++){
            vector<int> curr(W+1, 0);
            for(int j = 0; j <= W; j++){
                int notTake = dp[j];
                int take = 0;
                if(j >= wt[i]) take = curr[j - wt[i]] + val[i];
                curr[j] = max(take, notTake);
            }
            dp = curr;
        }
        return dp[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends