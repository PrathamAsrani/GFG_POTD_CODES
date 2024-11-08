//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        unordered_map<char, int> mp;
        for(char &ch: s1)
            mp[ch]++;
        for(char &ch: s2){
            if(mp.find(ch) == mp.end()){
                return -1;
            }
        }
        string s = s1;
        int rep = ceil((double)s2.size()/s1.size())+2;
        while(s.find(s2) == string::npos && rep--){
            s += s1;
        }
        if(rep <= 0) 
            return -1;
        return s.size()/s1.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends