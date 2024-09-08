//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& grid) {
        // Code here
        vector<int> dp(n);
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(n);
            for(int j = 0; j < grid[i].size(); j++){
                if(i == n-1) curr[j] = grid[i][j];
                else{
                    int mini = dp[j];
                    if(j+1 < n && mini > dp[j+1]){
                        mini = dp[j+1];
                    }
                    curr[j] = mini + grid[i][j];
                }
            }
            dp = curr;
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
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends