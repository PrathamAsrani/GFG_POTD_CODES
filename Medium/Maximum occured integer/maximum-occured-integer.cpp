//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        vector<int> dp(1e6+1, 0);
        int maxi = -1e6;
        for(int i = 0; i < n; i++){
            dp[l[i]]++;
            dp[r[i]+1]--;
            if(r[i] > maxi) maxi = r[i];
        }
        int ans = 0, mx = dp[0];
        for(int i = 1; i <= maxi; i++){
            dp[i] += dp[i-1];
            if(dp[i] > mx){
                mx = dp[i];
                ans = i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends