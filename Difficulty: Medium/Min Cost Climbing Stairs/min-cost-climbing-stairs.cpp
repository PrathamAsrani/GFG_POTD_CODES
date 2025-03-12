//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
    vector<int> dp;
    int climb(vector<int> &cost, int idx){
        if(idx >= cost.size()){
            return 0;
        }
        else if(dp[idx] != -1){
            return dp[idx];
        }
        
        return dp[idx] = min(climb(cost, idx+1), climb(cost, idx+2)) + cost[idx];
    }
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        dp.resize(cost.size()+1, -1);
        return min(climb(cost, 0), climb(cost, 1));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends