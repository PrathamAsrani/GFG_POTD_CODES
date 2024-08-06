//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        stringstream ss(str);
        string s;
        int cnt = 0;
        while(getline(ss, s, '.')){
            if(s.empty() || (s[0] == '0' && s.size() > 1)) 
                return false;
            int num = 0;
            for(int i = 0; i < s.size(); i++){
                num = num*10 + (s[i]-'0');
            }
            if(num < 0 || num > 255)
                return false;
            cnt++;
        }
        return cnt == 4;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends