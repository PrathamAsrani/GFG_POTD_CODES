//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = 1003;
    vector<vector<vector<int>>> dp;
    pair<int, int> fun(string &s, int i, int j){
        if(i == j){
            // if current exp is True then return {1, 0}
            if(s[i] == 'T') return {1, 0};
            // else return {0, 1}
            return {0, 1};
        }
        if(dp[i][j][0] != -1) return {dp[i][j][0], dp[i][j][1]};
        
        int t = 0, f = 0;
        for(int k = i+1; k <= j-1; k += 2){
            auto left = fun(s, i, k-1);
            auto right = fun(s, k+1, j);
            
            int left_true = left.first, left_false = left.second;
            int right_true = right.first, right_false = right.second;
            
            if(s[k] == '&'){
                t = (t + left_true*right_true)%mod;
                f = (f + left_true*right_false + left_false*right_true + left_false*right_false)%mod;
            }
            else if(s[k] == '|'){
                t = (t + left_true*right_true + left_true*right_false + left_false*right_true)%mod;
                f = (f + left_false*right_false)%mod;
            }
            else if(s[k] == '^'){
                t = (t + left_true*right_false + left_false*right_true)%mod;
                f = (f + left_false*right_false + left_true*right_true)%mod;
            }
        }
        dp[i][j][0] = t;
        dp[i][j][1] = f;
        return {t, f};
    }
public:
    int countWays(int n, string s){
        // code here
        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return fun(s, 0, n-1).first;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends