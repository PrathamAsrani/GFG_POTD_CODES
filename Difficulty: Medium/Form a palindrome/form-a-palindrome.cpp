//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    vector<vector<int>> dp;
    int LPS(int i, int j, string &s){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]){
            if(i == j) return dp[i][j] = 1 + LPS(i+1, j-1, s);
            else return dp[i][j] = 2 + LPS(i+1, j-1, s);
        } else {
            return dp[i][j] = max(LPS(i+1, j, s), LPS(i, j-1, s));
        }
    }
  public:
    int countMin(string str){
        int n = str.size();
        dp.resize(n, vector<int>(n, -1));
        return n - LPS(0, n-1, str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends