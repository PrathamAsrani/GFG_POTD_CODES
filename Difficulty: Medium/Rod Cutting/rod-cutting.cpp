//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<int> dp;
    int fun(int arr[], int len){
        if(len == 0) return 0;
        if(dp[len] != -1) return dp[len];
        
        int ans = 0;
        for(int cut = 1; cut <= len; cut++){
            ans = max(ans, fun(arr, len-cut) + arr[cut-1]);
        }
        return dp[len] = ans;
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        /*
        dp.resize(100001, -1);
        return fun(price, n);
        */
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends