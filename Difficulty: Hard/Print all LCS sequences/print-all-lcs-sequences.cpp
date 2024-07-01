//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    //  ---------------------------- approach 1 ----------------------------
    set<string> ans;
    int n, m;
    
    void helper(string &s, string &t, int i, int j, vector<vector<pair<int, vector<char>>>> &dp, string sub){
        if(i == 0 || j == 0){
            ans.insert(sub);
            return ;
        }
        auto it = dp[i][j].second;
        if(it.size() == 1){
            if(it[0] == 'D'){
                helper(s, t, i-1, j-1, dp, s[i-1]+sub);
            }else if(it[0] == 'U'){
                helper(s, t, i-1, j, dp, sub);
            }else{
                helper(s, t, i, j-1, dp, sub);
            }
        }else{
            helper(s, t, i-1, j, dp, sub);
            helper(s, t, i, j-1, dp, sub);
        }
    }
    
    //  ---------------------------- approach 2 ----------------------------
    vector<vector<int>> dp;
    int lcsLen;
    
    void LCS(string &s, string &t)
    {
        n = s.size(), m = t.size();
        dp.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } 
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
    }
    
    void findAllLCS(string &s, string &t, int i, int j, string &currentLCS, set<string> &allLCS) {
        if (i == 0 || j == 0) {
            if (currentLCS.size() == lcsLen) {
                allLCS.insert(currentLCS);
            }
            return;
        }
    
        if (s[i - 1] == t[j - 1]) {
            currentLCS = s[i - 1] + currentLCS;
            findAllLCS(s, t, i - 1, j - 1, currentLCS, allLCS);
            currentLCS.erase(currentLCS.begin());
        } else {
            if (dp[i - 1][j] == dp[i][j]) {
                findAllLCS(s, t, i - 1, j, currentLCS, allLCS);
            }
            if (dp[i][j - 1] == dp[i][j]) {
                findAllLCS(s, t, i, j - 1, currentLCS, allLCS);
            }
        }
    }
    
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    /*
		    // approach 1
		    n = s.size(), m = t.size();
		    vector<vector<pair<int, vector<char>>>> dp(n+1, vector<pair<int, vector<char>>>(m+1, {0, {}}));
		    for(int i = 1; i <= n; i++){
		        for(int j = 1; j <= m; j++){
		            if(s[i-1] == t[j-1]){
		                dp[i][j].first = dp[i-1][j-1].first+1;
		                dp[i][j].second.push_back('D');
		            }else{
		                if(dp[i-1][j].first > dp[i][j-1].first){
		                    dp[i][j].first = dp[i-1][j].first;
		                    dp[i][j].second.push_back('U');
		                }else if(dp[i-1][j].first < dp[i][j-1].first){
		                    dp[i][j].first = dp[i][j-1].first;
		                    dp[i][j].second.push_back('S');
		                }else{
		                    dp[i][j].first = dp[i][j-1].first;
		                    dp[i][j].second.push_back('S');
		                    dp[i][j].second.push_back('U');
		                }
		            }
		        }
		    }
		    //  cout << dp[n][m].first << "\n";
		    helper(s, t, n, m, dp, "");
		    return vector<string>(ans.begin(), ans.end());
		    */
            
            
            /*
            // approach 2		    
		    LCS(s, t);
            lcsLen = dp[n][m];
            set<string> allLCS;
            string currentLCS = "";
            findAllLCS(s, t, n, m, currentLCS, allLCS);
        
            return vector<string>(allLCS.begin(), allLCS.end());
            */
            
            // approach 3
            LCS(s, t);
            unordered_map<string, bool> umpp;
            set<string> st;
            queue<pair<pair<int, int>, string>> q;
            
            q.push({{0, 0}, ""});
            
            while(!q.empty()){
                auto it = q.front(); q.pop();
                pair<int, int> idx = it.first;
                string path = it.second;
                int i = idx.first, j = idx.second;
                
                if(i == n || j == m){
                    st.insert(path);
                    continue;
                }
                
                string key = to_string(i) + "," + to_string(j) + "," + path;
                if(umpp.find(key) != umpp.end()) 
                    continue;
                umpp[key] = true;
                
                if(s[i] == t[j]){
                    q.push({{i+1, j+1}, path+s[i]});
                }else{
                    if(dp[i+1][j] >= dp[i][j+1]){
                        q.push({{i+1, j}, path});
                    }
                    if(dp[i][j+1] >= dp[i+1][j]){
                        q.push({{i, j+1}, path});
                    }
                }
            }
            return vector<string>(st.begin(), st.end());
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends