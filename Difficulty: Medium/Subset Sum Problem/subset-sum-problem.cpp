//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int n;
    vector<vector<int>> dp;
    bool fun(vector<int> &arr, int sum, int idx = 0){
        if(sum == 0)
            return true;
        else if(idx >= n)
            return false;
        else if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        bool res = false;
        if(sum >= arr[idx])
            res = fun(arr, sum - arr[idx], idx+1) || fun(arr, sum, idx+1);
        else
            res = fun(arr, sum, idx+1);
        return dp[idx][sum] = res;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        n = arr.size();
        dp.resize(n, vector<int>(sum+1, -1));
        return fun(arr, sum, 0);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends