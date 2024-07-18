//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<vector<vector<int>>> dp;
  public:
    int f(int idx, int prev, bool flag, vector<int> &arr) {
        if(idx == arr.size()) return 0;
        if(dp[idx][prev+1][flag] != -1) return dp[idx][prev+1][flag];
        
        int notTake = f(idx+1, prev, flag, arr);
        int take = 0;
        if(prev == -1 || flag and arr[idx] > arr[prev]) {
            take = 1 + f(idx+1, idx, !flag, arr);
        } else if(!flag and arr[idx] < arr[prev]) {
            take = 1 + f(idx+1, idx, !flag, arr);
        }
        return dp[idx][prev+1][flag] = max(take, notTake);
    }
    int alternatingMaxLength(vector<int>& arr) {
        int n = arr.size();
        
        /*
        dp.resize(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return max(f(0, -1, true, arr), f(0, -1, false, arr));
        */
        
        /*
        int memo[n][2];
        memset(memo, 0, sizeof(memo));
        memo[0][0] = memo[0][1] = 1;
        int ans = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i] && memo[i][0] < memo[j][1]+1) {
                    memo[i][0] = memo[j][1]+1;
                }
                else if(arr[j] > arr[i] && memo[i][1] < memo[j][0]+1) {
                    memo[i][1] = memo[j][0]+1;
                } 
                ans = max({ans, memo[i][0], memo[i][1]});
            }
        }
        return ans;
        */
        
        int inc = 1, dec = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                inc = dec+1;
            } else if (arr[i] < arr[i-1]) {
                dec = inc+1;
            }
        }
        return max(inc, dec);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends