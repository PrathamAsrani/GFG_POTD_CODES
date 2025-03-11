//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<int> dp;
    int fib(int n){
        if(n <= 2) 
            return n;
        else if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = fib(n-1) + fib(n-2);
    }
  public:
    int countWays(int n) {
        // your code here
        dp.resize(n+1, -1);
        return fib(n);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends