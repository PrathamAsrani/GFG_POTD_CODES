//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    typedef long long ll;
    ll power(ll n, ll x){
        ll res = 1;
        while(x){
            if(x&1)
                res *= n;
            n = n*n;
            x >>= 1;
        }
        return res;
    }
  public:
    long long count(int n) {
        // your code here
        int x = n*(n-1)/2;
        return power(2, x);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    }

    return 0;
}

// } Driver Code Ends