//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string lexicographicallySmallest(string s, int k) {
        // code here
        int n = s.size();
        if(n != 0 && !(n & (n-1))){
            k /= 2;
        } else k *= 2;
        if(k >= n) return "-1";
        stack<char> st;
        for(char c: s){
            while(k > 0 && !st.empty() && st.top() > c){
                k--;
                st.pop();
            }
            st.push(c);
        }
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res == "" ? "-1" : res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends