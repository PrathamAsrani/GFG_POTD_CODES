//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    typedef long long int lli;
    int mod = 1e9+7;
    lli dp[1001][1001];
    
    lli fun(string &s, int i, int j){
        if(i == j) return 1;
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        lli cnt = 0;
        if(s[i] == s[j]){
            cnt = (1 + fun(s, i+1, j) + fun(s, i, j-1))%mod;
        } else {
            cnt = (fun(s, i+1, j) + fun(s, i, j-1) - fun(s, i+1, j-1) + mod)%mod;
        }
        return dp[i][j] = cnt;
    }
    public:
    /*You are required to complete below method */
    long long int countPS(string &s)
    {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return fun(s, 0, n-1);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends