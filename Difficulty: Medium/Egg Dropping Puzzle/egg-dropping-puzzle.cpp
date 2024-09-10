//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int fun(int e, int f){
        if(f == 0 || f == 1 || e == 1) return f;
        if(dp[e][f] != -1) return dp[e][f];
        
        int moves = 1e9;
        for(int k = 1; k <= f; k++){
            int tmp = 1 + max(fun(e-1, k-1), fun(e, f-k));
            moves = min(moves, tmp);
        }
        return dp[e][f] = moves;
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        return fun(e, f);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends