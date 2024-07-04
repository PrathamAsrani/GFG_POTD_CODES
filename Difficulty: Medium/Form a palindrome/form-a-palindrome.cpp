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
    int findMinInsertions(string s){
        n = s.size();
        return n - LPS(s);
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