//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<vector<int>> dp;
    int n;
    int fun(vector<int> &wt, vector<int>& val, int i, int cap){
        if(i == n) return 0;
        if(dp[i][cap] != -1) return dp[i][cap];
        
        int notTake = fun(wt, val, i+1, cap);
        int take = 0;
        if(cap >= wt[i]){
            take = fun(wt, val, i+1, cap-wt[i]) + val[i];
        }
        return dp[i][cap] = max(take, notTake);
    }
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        n = wt.size();
        dp.resize(n, vector<int>(W+1, -1));
        return fun(wt, val, 0, W);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends