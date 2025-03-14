//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int n;
    vector<vector<int>> dp;
    int fun(vector<int> &coins, int sum, int idx = 0){
        if(idx >= n)
            return sum == 0 ? 1 : 0;
        else if(sum == 0)
            return 1;
        else if(sum < 0)
            return 0;
        else if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        int take = 0, notTake = fun(coins, sum, idx+1);
        if(sum >= coins[idx]){
            take = fun(coins, sum - coins[idx], idx);
        }
        
        return dp[idx][sum] = take + notTake;
    }
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        n = coins.size();
        dp.resize(n, vector<int>(sum + 1, -1));
        return fun(coins, sum);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends