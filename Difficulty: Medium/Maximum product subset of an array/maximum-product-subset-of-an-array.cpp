//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    using lli = long long int;
    int mod = 1e9+7;
  public:
    /*
    // Approach 1:
    lli findMaxProduct(vector<int>& arr, int i = 0, lli prod = 1) {
        if(i >= arr.size()) return prod;
        lli take = findMaxProduct(arr, i+1, (prod*arr[i])%mod);
        lli notTake = findMaxProduct(arr, i+1, prod);
        return max(take, notTake);
    }
    */
    
    // Approach 2:
    lli findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        lli prod = 1;
        int mini = -1e9, neg = 0;
        for(auto &x: arr){
            if(x < 0) {
                neg++;
                if(x > mini)
                    mini = x; // find maximum neg num
            }
            if(x != 0)
                prod = (prod * abs(x))%mod;
        }
        if(mini != -1e9 && neg&1) {
            prod = abs(prod/mini);
        }
        return prod;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends