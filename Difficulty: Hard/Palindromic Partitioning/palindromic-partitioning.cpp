//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int>> dp;
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return 0;
        }
        return 1;
    }
public:
    int fun(string &s, int i, int j){
        if(i >= j || isPalindrome(s, i, j)) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int cuts = 1e9;
        for(int k = i; k <= j; k++){
            if(isPalindrome(s, i, k)){
                cuts = min(cuts, fun(s, k+1, j) + 1);
            }
        }
        return dp[i][j] = cuts;
    }
    int palindromicPartition(string &s)
    {
        // code here
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return fun(s, 0, s.size()-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends