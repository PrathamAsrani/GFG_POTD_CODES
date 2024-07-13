//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void helper(int arr[], int l, int r, int &mini){
        if(l > r) return ;
        if(l == r) {
            if(mini > arr[l]) mini = arr[l];
            return ;
        }
        int m = (l+r)/2;
        helper(arr, l, m, mini);
        helper(arr, m+1, r, mini);
    }
    int findMin(int arr[], int n) {
        int mini = 1e9;
        helper(arr, 0, n-1, mini);
        return mini;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.findMin(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends