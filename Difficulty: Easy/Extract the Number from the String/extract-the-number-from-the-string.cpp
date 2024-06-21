//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

typedef long long ll;

class Solution {
  public:
    ll ExtractNumber(string str) {
        ll ans = -1;
        stringstream ss(str);
        string s;
        auto check = [](string &s) -> pair<bool, ll> {
            ll num = 0LL;
            for(char &c: s) {
                if(c == '9') return {false, 0LL};
                num = num*10 + c-'0';
            }
            return {true, num};
        };
        while(getline(ss, s, ' ')){
            if(s[0] >= '0' and s[s.size()-1] <= '9'){
                pair<bool, ll> it = check(s);
                if(it.first == true and it.second > ans) {
                    ans = it.second;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends