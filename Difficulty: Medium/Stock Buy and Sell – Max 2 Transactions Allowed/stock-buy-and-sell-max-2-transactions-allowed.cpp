//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    vector<vector<vector<int>>> dp;
    int n;
    int fun(int i, bool buy, int trans, vector<int> &arr){
        if(i == n || trans == 0) return 0;
        if(dp[i][buy][trans] != -1) return dp[i][buy][trans];

        int ans = 0;
        if(buy == true){
            ans = max(fun(i+1, 0, trans, arr) - arr[i], fun(i+1, buy, trans, arr));
        } else {
            ans = max(fun(i+1, 1, trans-1, arr) + arr[i], fun(i+1, buy, trans, arr));
        }
        return dp[i][buy][trans] = ans;
    }
    public:
        int maxProfit(vector<int>&arr){
            n = arr.size();
            dp.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));
            return fun(0, 1, 2, arr);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends