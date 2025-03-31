//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<int, int> lastIndex;
        int n = s.size(), ans = 0;
        if(n <= 0)
            return 0;
        for(int i = 0; i < n; i++){
            lastIndex[s[i]] = i;
        }
        int last = lastIndex[s[0]], len = 0;
        for(int i = 0; i < n; i++){
            if(i <= last){
                len++;
                last = max(last, lastIndex[s[i]]);
            }
            else{
                len = 1;
                ans++;
                last = max(last, lastIndex[s[i]]);
            }
        }
        if(len != 0)
            return ans+1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends