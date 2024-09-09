//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<vector<vector<int>>> dp;
  public:
    int fun(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid){
        if(i == n) return 0;
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return 0;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int ans = 0;
        for(int x = -1; x <= 1; x++){
            for(int y = -1; y <= 1; y++){
                int cost = 0;
                if(j1 == j2) cost = grid[i][j1];
                else cost = grid[i][j1] + grid[i][j2];
                ans = max(ans, fun(i+1, j1+x, j2+y, n, m, grid) + cost);
            }
        }
        
        return dp[i][j1][j2] = ans;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return fun(0, 0, m-1, n, m, grid);
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends