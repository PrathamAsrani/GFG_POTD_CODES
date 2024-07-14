//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& hei, int n) {
        // Code here
        int dp[n];
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            int two = 1e9;
            int one = dp[i-1] + abs(hei[i] - hei[i-1]);
            if(i > 1) two = dp[i-2] + abs(hei[i] - hei[i-2]);
            
            dp[i] = min(one, two);
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