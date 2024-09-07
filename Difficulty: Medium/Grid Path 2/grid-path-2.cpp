//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        int mod = 1e9+7;
        vector<int> dp(m, 0), curr;
        if(grid[0][0] == 1) return 0;
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            curr.assign(m, 0);
            curr[0] = 1;
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) {
                    curr[0] = 1;
                    continue;
                }
                if(grid[i][j]){
                    curr[j] = 0;
                    continue;
                }
                int ways = 0;
                if(i > 0) ways = (ways + dp[j])%mod;
                if(j > 0) ways = (ways + curr[j-1])%mod;
                curr[j] = ways;
            }
            dp = curr;
        }
        return dp[m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends