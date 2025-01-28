//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    set<string> ans;
    void helper(string &s, int idx){
        if(idx == s.size()){
            ans.insert(s);
            return ;
        }
        for(int i = idx; i < s.size(); i++){
            swap(s[i], s[idx]);
            helper(s, idx+1);
            swap(s[i], s[idx]);
        }
    }
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        helper(s, 0);
        return vector<string>(ans.begin(), ans.end());
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends