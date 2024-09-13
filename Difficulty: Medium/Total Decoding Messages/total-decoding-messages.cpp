//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod = 1e9+7;
    vector<int> dp;
    int fun(string &s, int i, int n){
        // base case: one way to decode string is found
        if(i >= n) return 1;
        // constraint given
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        
        // currently not taking ith in decoding
        int notTake = fun(s, i+1, n);
        int take = 0;
        if(i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
            take = fun(s, i+2, n);
        return dp[i] = (take + notTake)%mod;
    }
	public:
		int CountWays(string str){
		    // Code here
		    dp.assign(str.size(), -1);
		    return fun(str, 0, str.size());
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends