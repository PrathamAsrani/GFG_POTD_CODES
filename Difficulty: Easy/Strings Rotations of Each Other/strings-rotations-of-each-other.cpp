//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    vector<int> buildLPS(const string &pattern) {
            int n = pattern.size();
            vector<int> lps(n, 0);
            int length = 0, i = 1;
        
            while (i < n) {
                if (pattern[i] == pattern[length]) {
                    length++;
                    lps[i] = length;
                    i++;
                } else {
                    if (length != 0) {
                        length = lps[length - 1];
                    } else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            return lps;
        }
        
        // KMP Substring Search
        bool kmpSearch(const string &text, const string &pattern) {
            vector<int> lps = buildLPS(pattern);
            int i = 0, j = 0; // i -> text, j -> pattern
        
            while (i < text.size()) {
                if (text[i] == pattern[j]) {
                    i++;
                    j++;
                }
                if (j == pattern.size()) {
                    return true; // Match found
                } else if (i < text.size() && text[i] != pattern[j]) {
                    if (j != 0) {
                        j = lps[j - 1];
                    } else {
                        i++;
                    }
                }
            }
            return false;
        }
        
        // Check if s2 is a rotation of s1
        bool areRotations(string s1, string s2) {
            if (s1.length() != s2.length()) return false;
            string concatenated = s1 + s1;
            return kmpSearch(concatenated, s2);
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