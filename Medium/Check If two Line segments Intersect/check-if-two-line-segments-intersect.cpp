//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int getOrient(int a[], int b[], int c[]) {
        long long val = (long long)(b[1] - a[1]) * (c[0] - b[0]) - (long long)(b[0] - a[0]) * (c[1] - b[1]);
        int orient = 0;
        if (val > 0) {
            orient = 1;
        } else if (val < 0) {
            orient = 2;
        }
        return orient;
    }

    bool onSegment(int a[], int b[], int c[]) {
        return (b[1] <= max(a[1], c[1]) && b[1] >= min(a[1], c[1]) &&
                b[0] <= max(a[0], c[0]) && b[0] >= min(a[0], c[0]));
    }

    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        int o1 = getOrient(p1, q1, p2);
        int o2 = getOrient(p1, q1, q2);
        int o3 = getOrient(p2, q2, p1);
        int o4 = getOrient(p2, q2, q1);

        if (o1 != o2 && o3 != o4) {
            return "true";
        }
        if (o1 == 0 && onSegment(p1, p2, q1)) return "true";
        if (o2 == 0 && onSegment(p1, q2, q1)) return "true";
        if (o3 == 0 && onSegment(p2, p1, q2)) return "true";
        if (o4 == 0 && onSegment(p2, q1, q2)) return "true";

        return "false";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends