//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<vector<int>> dp;
    int fun(int idx, vector<int> &val, vector<int> &wt, int &cap){
        if(idx >= val.size()) 
            return 0;
        else if(dp[idx][cap] != -1)
            return dp[idx][cap];
        
        int take = 0, notTake = fun(idx+1, val, wt, cap);
        if(cap >= wt[idx]){
            cap -= wt[idx];
            take = fun(idx+1, val, wt, cap) + val[idx];
            cap += wt[idx];
        }
        return dp[idx][cap] = max(take, notTake);
    }
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        dp.resize(val.size(), vector<int>(W+1, -1));
        return fun(0, val, wt, W);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends