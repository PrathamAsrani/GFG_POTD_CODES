//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        int idx = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' '){
                continue;
            }
            str[idx++] = str[i];
        }
        str.erase(idx);
        if(str.size() < 26) return 0;
        int dp[26] = {0};
        for(char c: str) dp[c-'a']++;
        int cnt = 0;
        for(int i = 0; i < 26; i++) if(dp[i] == 0) cnt++;
        return k >= cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends