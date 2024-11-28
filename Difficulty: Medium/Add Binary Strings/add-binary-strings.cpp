//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string ans;
        int n = s1.size(), m = s2.size();
        int i = n-1, j = m-1, carry = 0;
        while(i >= 0 || j >= 0){
            int a = (i >= 0 ? s1[i]-'0' : 0);
            int b = (j >= 0 ? s2[j]-'0' : 0);
            if(a+b+carry == 3){
                ans = '1' + ans;
                carry = 1;
            }
            else if(a+b+carry == 2){
                ans = '0' + ans;
                carry = 1;
            }
            else if(a+b+carry == 1){
                ans = '1' + ans;
                carry = 0;
            }
            else ans = '0' + ans;
            if(i >= 0) i--;
            if(j >= 0) j--;
        }
        if(carry == 1){
            ans = '1' + ans;
        }
        int idx = -1;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] != '0') {
                idx = i;
                break;
            }
        }
        if(idx != -1)
            return ans.substr(idx);
        return "";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends