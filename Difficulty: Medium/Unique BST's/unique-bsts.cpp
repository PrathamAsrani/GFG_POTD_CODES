//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int mod = 1e9+7;
    int dp[1001][1001];
    //Function to return the total number of possible unique BST. 
    int createBSTs(int start, int end){
        if(start >= end) return 1;
        if(dp[start][end] != -1) return dp[start][end];
        
        long ans = 0;
        for(int i = start; i <= end; i++){
            long left = createBSTs(start, i-1);
            long right = createBSTs(i+1, end);
            ans = (ans + left*right)%mod;
        }
        return dp[start][end] = ans;
    }
    long helper(int n, int dp[]){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        
        long ans = 0;
        for(int i = 1; i <= n; i++)
            ans = (ans + helper(i-1, dp) * helper(n-i, dp))%mod;
        
        return dp[n] = ans;
    }
    int numTrees(int N) 
    {
        // Your code here
        /*
        memset(dp, -1, sizeof(dp));
        return createBSTs(1, N);
        */
        
        int dp[N+1];
        fill_n(dp, N+1, -1);
        return helper(N, dp);
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends