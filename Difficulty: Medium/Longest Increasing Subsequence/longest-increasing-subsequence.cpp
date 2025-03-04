//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int n;
    vector<vector<int>> dp;
    int TD(int idx, int prev, vector<int> &arr){
        if(idx >= n)
            return 0;
        else if(dp[idx][prev+1] != -1)
            return dp[idx][prev+1];
        
        int take = 0;
        if(prev == -1 || arr[idx] > arr[prev]){
            take = 1 + TD(idx+1, idx, arr);
        }
        int notTake = TD(idx+1, prev, arr);
        return dp[idx][prev+1] = max(take, notTake);
    }
  public:
    int lis(vector<int>& arr) {
        // code here
        // TD: 
        n = arr.size();
        dp.resize(n, vector<int>(n+1, -1));
        // return TD(0, -1, arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends