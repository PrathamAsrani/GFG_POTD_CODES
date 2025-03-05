//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int isPredecessor(string &a, string &b){
        int n = a.size(), m = b.size(), i, j;
        if(n+1 != m) 
            return false;
        for(i = 0, j = 0; j < m; ){
            if(a[i] == b[j]){
                i++, j++;
            }
            else j++;
        }
        return i == n && j == m;
    }
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [&](string &a, string &b) {
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPredecessor(words[j], words[i]) && dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends