class Solution {
    int n;
    vector<vector<int>> dp;
    int f(int idx, int buy, vector<int> &arr, int &k){
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int ans = 0;
        if(buy == 0){
            ans = max(
                    f(idx+1, buy, arr, k), // buy in future
                    f(idx+1, 1, arr, k) - arr[idx] // buy today
                );
        }
        else if(buy == 1){
            ans = max(
                    f(idx+1, buy, arr, k), // sell in future
                    f(idx+1, 0, arr, k) + arr[idx] - k // sell today
                );
        }
        return dp[idx][buy] = ans;
    }
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        // state 0: buy
        // state 1: sell
        this->n = arr.size();
        dp.resize(n, vector<int>(2, -1));
        return f(0, 0, arr, k);
    }
};