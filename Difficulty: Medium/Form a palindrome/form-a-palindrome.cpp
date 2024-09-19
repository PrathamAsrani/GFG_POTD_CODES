//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    int n;
public:
    int LPS(string &s){
        vector<int> dp(n, 0);
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(n, 0);
            curr[i] = 1;
            for(int j = i+1; j < n; j++){
                int val = 0;
                if(s[i] == s[j]){
                    val = 2 + dp[j-1];
                }else{
                    val = max(dp[j], curr[j-1]);
                }
                curr[j] = val;
            }
            dp = curr;
        }
        return dp[n-1];
    }
    
    int LCS(string &s, string &t){
        int n = s.size(), m = t.size();
        vector<int> dp(m+1, 0);
        
        for(int i = 1; i <= n; i++){
            vector<int> curr(m+1, 0);
            for(int j = 1; j <= m; j++){
                int val = 0;
                if(s[i-1] == t[j-1]){
                    val = 1 + dp[j-1];
                }else{
                    val = max(dp[j], curr[j-1]);
                }
                curr[j] = val;
            }
            dp = curr;
        }
        return dp[m];
    }
        
    int findMinInsertions(string s){
        n = s.size();
        
        // 1. Longest Palindrome Subseq
        // return n - LPS(s);
        
        string t = s;
        reverse(s.begin(), s.end());
        return n - LCS(s, t);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends