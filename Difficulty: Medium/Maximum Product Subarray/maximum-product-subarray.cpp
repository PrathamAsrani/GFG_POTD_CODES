//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    typedef long long ll;
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    ll mini, maxi, ans;
	    mini = maxi = ans = arr[0];
	    for(int i = 1; i < n; i++){
	        ll tmp = max({(ll) arr[i], arr[i] * mini, arr[i] * maxi});
	        mini = min({(ll) arr[i], arr[i]*mini, arr[i]*maxi});
	        maxi = tmp;
	        ans = max(ans, maxi);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends