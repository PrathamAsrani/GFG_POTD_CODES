//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    int isPalindrome(string &s, int i, int j, vector<vector<int>> &memo){
        if(i == j) return 1;
        else if(i == j-1) return s[i] == s[j] ? 1 : 0;
        else if(memo[i][j] != -1) return memo[i][j];
        
        return memo[i][j] = (s[i] == s[j] && isPalindrome(s, i+1, j-1, memo));
    }
  public:
    int countPS(string &s) {
        // code here
        /*
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1+i; j < n; j++){
                int l = i, r = j;
                bool isPalin = true;
                while(l < r){
                    if(s[l] != s[r]){
                        isPalin = false;
                        break;
                    }
                    l++;
                    r--;
                }
                if(isPalin){
                    ans++;
                }
            }
        }
        return ans;
        */
        
        int n = s.size(), ans = 0;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isPalindrome(s, i, j, memo))
                    ans++;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends