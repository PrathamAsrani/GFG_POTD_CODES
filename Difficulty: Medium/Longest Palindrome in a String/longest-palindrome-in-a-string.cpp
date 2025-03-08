//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int st = -1, len = 0;
        int n = s.size();
        if(n <= 0){
            return "";
        }
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            // for odd length palin
            while(l >= 0 && r < n && s[l] == s[r]){
                if(len < (r-l+1)){
                    len = r-l+1;
                    st = l;
                }
                l--;
                r++;
            }
            // for even length palin
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(len < (r-l+1)){
                    len = r-l+1;
                    st = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(st, len);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends