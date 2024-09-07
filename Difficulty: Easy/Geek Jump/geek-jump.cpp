//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int k = 2;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++){
            int step = 1e9;
            for(int j = i-1; j >= max(0, i-k); j--){
                step = min(step, dp[j] + abs(height[j] - height[i]));
            }
            dp[i] = step == 1e9 ? 0 : step;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends