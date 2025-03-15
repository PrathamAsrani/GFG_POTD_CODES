//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int n;
    vector<vector<int>> dp;
    int fun(vector<int> &coins, int sum, int idx = 0){
        if(idx >= n)
            return sum == 0 ? 0 : 1e5;
        else if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        int notTake = fun(coins, sum, idx+1), take = 1e5;
        if(sum >= coins[idx])
            take = fun(coins, sum-coins[idx], idx) + 1;
        
        return dp[idx][sum] = min(take, notTake);
    }
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        n = coins.size();
        dp.resize(n, vector<int>(sum+1, -1));
        int ans = fun(coins, sum);
        return ans == 100000 ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends