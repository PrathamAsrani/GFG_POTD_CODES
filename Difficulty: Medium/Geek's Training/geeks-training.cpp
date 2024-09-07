//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 3; j++){
                int point = 0;
                point = max({point, arr[i][j] + dp[i+1][(j+1)%3], arr[i][j] + dp[i+1][(j+2)%3]});
                dp[i][j] = point;
            }
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends