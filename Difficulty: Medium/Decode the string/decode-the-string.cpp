//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    string fun(int &idx, string &s){
        string res;
        int rep = 0;
        
        while(idx < s.size()){
            if(isdigit(s[idx])){
                rep = rep*10 + (s[idx] - '0');
            }
            else if(s[idx] == '['){
                idx++;
                string sub = fun(idx, s);
                while(rep--){
                    res += sub;
                }
                rep = 0;
            }
            else if(s[idx] == ']'){
                return res;
            }
            else {
                res += s[idx];
            }
            idx++;
        }
        return res;
    }
  public:
    string decodedString(string &s) {
        // code here
        int idx = 0;
        return fun(idx, s);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends