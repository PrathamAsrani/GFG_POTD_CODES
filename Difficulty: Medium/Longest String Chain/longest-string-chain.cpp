//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPredecessor(string &a, string &b){
        if(a.size()+1 != b.size()) return false;
        int i, j;
        int n = a.size(), m = b.size();
        for(i = 0, j = 0; j < m; ){
            if(a[i] == b[j]){
                i++, j++;
            } else j++;
        }
        return i == n and j == m;
    }
    int longestChain(int n, vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [&](string &a, string &b){
            return a.size() < b.size();
        });
        int ans = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPredecessor(words[j], words[i]) && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    if(ans < dp[i]) ans = dp[i];
                }
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
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends