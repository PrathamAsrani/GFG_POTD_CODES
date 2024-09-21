//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string &s) {
        // Your code goes here
        int n = s.size();
        vector<int> pi(n, 0);
        for(int i = 1; i < n; i++){
            int prev = pi[i-1];
            while(prev > 0 && s[prev] != s[i]){
                prev = pi[prev-1];
            }
            if(s[prev] == s[i]){
                prev++;
            }
            pi[i] = prev;
        }
        return pi[n-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends