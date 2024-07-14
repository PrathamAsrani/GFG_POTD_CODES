//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int helper(int idx, int prev, vector<vector<int>> &points, vector<vector<int>> &dp){
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int ans = 0;
        if(idx == 0) {
            for(int i = 0; i < 3; i++){
                if(prev == i) continue;
                ans = max(ans, points[idx][i]);
            }
            return dp[idx][prev+1] =  ans;
        }
        for(int i = 0; i < 3; i++){
            if(i == prev) continue;
            ans = max(ans, helper(idx-1, i, points, dp) + points[idx][i]);
        }
        return dp[idx][prev+1] = ans;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        /*
        // TOP DOWN
        // TC: O(N*4*3), SC: O(N*3) + O(N)
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helper(n-1, -1, points, dp);
        */
        
        /*
        vector<vector<int>> dp(n, vector<int>(4, 0));\
        // prev = -1, therefore max({day[0], day[1], day[2]})
        dp[0][0] = max({points[0][0], points[0][1], points[0][2]});
        // prev = 0, therefore max(day[1], day[2])
        dp[0][1] = max(points[0][1], points[0][2]);
        // prev = 1, therefore max(day[0], day[2])
        dp[0][2] = max(points[0][0], points[0][2]);
        // prev = 2, therefore max(day[0], day[1])
        dp[0][3] = max(points[0][0], points[0][1]);
    
        for(int idx = 1; idx < n; idx++){
            for(int prev = 0; prev < 4; prev++){
                int ans = 0;
                for(int i = 0; i < 3; i++){
                    if(i+1 == prev) continue;
                    ans = max(ans, dp[idx-1][i+1] + points[idx][i]);
                }
                dp[idx][prev] = ans;
            }
        }
        return dp[n-1][0];
        */
        
        vector<int> dp(4, 0);
        // prev = -1, therefore max({day[0], day[1], day[2]})
        dp[0] = max({points[0][0], points[0][1], points[0][2]});
        // prev = 0, therefore max(day[1], day[2])
        dp[1] = max(points[0][1], points[0][2]);
        // prev = 1, therefore max(day[0], day[2])
        dp[2] = max(points[0][0], points[0][2]);
        // prev = 2, therefore max(day[0], day[1])
        dp[3] = max(points[0][0], points[0][1]);
    
        for(int idx = 1; idx < n; idx++){
            vector<int> tmp(4, 0);
            for(int prev = 0; prev < 4; prev++){
                for(int i = 0; i < 3; i++){
                    if(i+1 == prev) continue;
                    tmp[prev] = max(tmp[prev], dp[i+1] + points[idx][i]);
                }
            }
            dp = tmp;
        }
        return dp[0];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends