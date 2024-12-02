//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int n, m;
        vector<int> prefix(string &s){
            vector<int> pi(m, 0);
            for(int i = 1; i < m; i++){
                int prev = pi[i-1];
                while(prev > 0 and s[prev] != s[i]){
                    prev = pi[prev-1];
                }
                if(s[prev] == s[i]){
                    prev++;
                }
                pi[i] = prev;
            }
            return pi;
        }
        vector <int> search(string s, string t)
        {
            vector <int> ans;
            n = t.size(), m = s.size();
            vector<int> p = prefix(s);
            int i = 0, j = 0;
            while(i < n){
                if(t[i] == s[j]){
                    i++, j++;
                }else{
                    if(j != 0){
                        j = p[j-1];
                    }else{
                        i++;
                    }
                }
                if(j == m){
                    ans.push_back(i - m);
                }
            }
            return ans;
        }
     
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends