//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int mod = 1e9+7;
    int dp[10001];
  public:
  Solution(){
      memset(dp, -1, sizeof(dp));
  }
    long long int topDown(int n) {
        // code here
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (topDown(n-1) + topDown(n-2))%mod;
    }
    long long int bottomUp(int n) {
        // code here
        int a = 0, b = 1;
        for(int i = 2; i <= n; i++){
            int c = (a+b)%mod;
            a = b;
            b = c;
        }
        return b;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends