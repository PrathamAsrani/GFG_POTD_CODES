//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int n;
    vector<vector<vector<int>>> dp;
    int fun(vector<int>& arr, int i, int trans, bool buy){
        if(i == n || trans == 0) return 0;
        if(dp[i][trans][buy] != -1) return dp[i][trans][buy];

        int val = fun(arr, i+1, trans, buy);
        if(buy){
            val = max(val, fun(arr, i+1, trans, !buy) - arr[i]);
        } else {
            val = max(val, fun(arr, i+1, trans-1, !buy) + arr[i]);
        }
        return dp[i][trans][buy] = val;
    }
  public:
    int maxProfit(vector<int>& prices, int k) {
        this->n = prices.size();
        dp.resize(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return fun(prices, 0, k, true);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends