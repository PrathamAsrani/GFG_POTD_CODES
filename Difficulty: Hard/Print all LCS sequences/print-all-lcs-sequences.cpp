//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    set<string> ans;
    unordered_map<string, bool> cache;
    void helper(int i, int j, string &s, string &t, vector<vector<pair<int, vector<char>>>> &dp, string sub){
        if(i == s.size() || j == t.size()){
            ans.insert(sub);
            return ;
        }
        string key = to_string(i) + "," + to_string(j) + "," + sub;
        if(cache.find(key) != cache.end()) return ;
        cache[key] = true;
        
        auto &it = dp[i][j].second;
        if(it.size() == 1){
            if(it[0] == 'D'){
                helper(i+1, j+1, s, t, dp, sub + s[i]);
            } else if(it[0] == 'U'){
                helper(i+1, j, s, t, dp, sub);
            } else {
                helper(i, j+1, s, t, dp, sub);
            }
        } else {
            helper(i+1, j, s, t, dp, sub);
            helper(i, j+1, s, t, dp, sub);
        }
    }
  public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        // Code here
        // approach 1:
        int n = s.size(), m = t.size();
        vector<vector<pair<int, vector<char>>>> dp(n+1, vector<pair<int, vector<char>>>(m+1, {0, {}}));
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(s[i] == t[j]){
                    dp[i][j].first = dp[i+1][j+1].first + 1;
                    dp[i][j].second.push_back('D');
                } else {
                    if(dp[i+1][j].first > dp[i][j+1].first){
                        dp[i][j].first = dp[i+1][j].first;
                        dp[i][j].second.push_back('U');
                    } else if(dp[i+1][j].first < dp[i][j+1].first){
                        dp[i][j].first = dp[i][j+1].first;
                        dp[i][j].second.push_back('S');
                    } else {
                        dp[i][j].first = dp[i][j+1].first;
                        dp[i][j].second.push_back('S');
                        dp[i][j].second.push_back('U');
                    }
                }
            }
        }
        helper(0, 0, s, t, dp, "");
        return vector<string>(ans.begin(), ans.end());
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends