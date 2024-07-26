//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return n;
        int ans = 2;
        
        /*
        vector<unordered_map<int, int>> dp(n);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = arr[i] - arr[j];
                if(dp[j].find(diff) == dp[j].end()) dp[i][diff] = 2;
                else dp[i][diff] = dp[j][diff]+1;
                ans = max(ans, dp[i][diff]);
            }
        }
        */
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) dp[i][n-1] = 2;
        
        for(int j = n-2; j > 0; j--){
            int i = j-1, k = j+1;
            while(i >= 0 && k < n){
                if(arr[i]+arr[k] == 2*arr[j]){
                    dp[i][j] = dp[j][k]+1;
                    ans = max(ans, dp[i][j]);
                    i--;
                    k++;
                } else if (arr[i]+arr[k] > arr[j]*2){
                    dp[i][j] = 2;
                    i--;
                } else {
                    k++;
                }
            }
            while(i >= 0)
                dp[i--][j] = 2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.lengthOfLongestAP(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends