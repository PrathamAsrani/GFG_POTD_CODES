//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef long long int lli;
  public:
    long long int count(int arr[], int n, int sum) {
        vector<lli> dp(sum+1, 0);
        dp[0] = 1;
        for(int i = n-1; i >= 0; i--){
            vector<lli> curr(sum+1, 0);
            curr[0] = 1;
            for(int j = 0; j <= sum; j++){
                lli notTake = dp[j], take = 0;
                if(j >= arr[i])
                    take = curr[j-arr[i]];
                curr[j] = take + notTake;
            }
            dp = curr;
        }
        return dp[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends