//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root

typedef long long int lli;
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        if(n == 0 || n == 1) return n;
        lli ans = 1, val = 1;
        while(val <= n) ans++, val = ans*ans;
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends