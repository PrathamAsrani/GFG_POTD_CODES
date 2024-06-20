//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

typedef long long int lli;

lli gcd(lli a, lli b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
    lli getBoundaryPoints(lli a[], lli b[]) {
        return gcd(abs(a[0] - b[0]), abs(a[1] - b[1])) + 1;
    }

    lli InternalCount(lli p[], lli q[], lli r[]) {
        // Calculate the area of the triangle using determinant method
        lli area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));

        // Calculate the number of boundary points
        lli B = getBoundaryPoints(p, q) + getBoundaryPoints(q, r) + getBoundaryPoints(r, p) - 3; // Subtracting 3 to avoid double counting vertices

        // Applying Pick's theorem
        lli I = (area - B + 2) / 2;

        return I;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends