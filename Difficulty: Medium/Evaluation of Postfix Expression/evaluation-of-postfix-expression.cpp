//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        for(string &s: arr){
            if(s.size() == 1 && (s[0] == '-' || s[0] == '+' || s[0] == '*' || s[0] == '/')){
                int tp1 = st.top(); st.pop();
                int tp2 = st.top(); st.pop();
                int res = 0;
                if(s[0] == '-')
                    res = tp2 - tp1;
                else if(s[0] == '+')
                    res = tp2 + tp1;
                else if(s[0] == '*')
                    res = tp2 * tp1;
                else if(s[0] == '/')
                    res = tp2 / tp1;
                st.push(res);
            }
            else{
                int num = 0;
                bool isNeg = s[0] == '-';
                for(int i = isNeg ? 1 : 0; i < s.size(); i++){
                    num = num*10 + (s[i] - '0');
                }
                if(isNeg) st.push(-num);
                else st.push(num);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends