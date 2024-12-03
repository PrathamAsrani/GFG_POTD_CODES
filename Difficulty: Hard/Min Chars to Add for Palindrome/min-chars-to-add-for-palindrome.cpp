//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int minChar(string &s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string concat = s + '#' + rev_s;
        int n = concat.size();

        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && concat[i] != concat[j]) {
                j = lps[j - 1];
            }
            if (concat[i] == concat[j]) {
                j++;
            }
            lps[i] = j;
        }

        return s.size() - lps[n - 1];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends