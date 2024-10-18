//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string s) {
        // Complete the function
        int carry = 0, n = s.size();
        for(int i = n-1; i >= 0; i--){
            int num = s[i] - '0';
            if(i == n-1){
                if(num <= 5){
                    s[i] = '0';
                    return s;
                } else {
                    s[i] = '0';
                    carry = 1;
                }
            } 
            else if(carry == 1) {
                if(s[i] == '9'){
                    s[i] = '0';
                }
                else{
                    s[i] = char(s[i]+1);
                    carry = 0;
                    return s;
                }
            }
        }
        if(carry == 1){
            return "1"+s;
        }
        return s;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends