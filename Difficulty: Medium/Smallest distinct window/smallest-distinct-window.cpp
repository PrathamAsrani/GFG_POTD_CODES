//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_map<char, int> mp;
        for(char &c: str)
            mp[c]++;
        int total = mp.size();
        int i = 0, j = 0, ans = str.size();
        mp.clear();
        for(j; j < str.size(); j++){
            mp[str[j]]++;
            while(mp.size() == total){
                ans = min(ans, j-i+1);
                mp[str[i]]--;
                if(mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends