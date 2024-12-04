//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<int> prefix(string &s){
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
        return pi;
    }
    bool KMP(string t, string p){
        vector<int> pi = prefix(p);
        int n = t.size(), m = p.size();
        int i = 0, j = 0;
        while(i < n){
            if(t[i] == p[j]){
                i++, j++;
            } else {
                if(j == m){
                    return true;
                }
                else if (j != 0) {
                    j = pi[j-1];
                }
                else {
                    i++;
                }
            }
        }
        return false;
    }
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        /*
        if(s1.size() != s2.size()) 
            return false;
        if(s1 == s2) 
            return true;
        for(int i = 1; i <= s1.size(); i++){
            string a = s1.substr(0, i);
            string b = s1.substr(i);
            // cout << a << " " << b << "\n";
            if(a+b == s2 || b+a == s2) 
                return true;
        }
        return false;
        */
        
        /*
        if(s1.size() != s2.size()) 
            return false;
        if(s1 == s2) 
            return true;
        
        queue<char> q1, q2;
        for(char &c: s1) q1.push(c);
        for(char &c: s2) q2.push(c);
        
        int i = 0;
        while(i++ < s1.size() && q1 != q2){
            q1.push(q1.front());
            q1.pop();
            if(q1 == q2) return 1;
            if(i == s1.size()) return 0;
        }
        return q1 == q2;
        */
        
        /*
        if(s1.size() != s2.size()) 
            return false;
        string res = s1+s1;
        return res.find(s2) != -1;
        */
        
        string res = s1+s1;
        return KMP(res, s2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends