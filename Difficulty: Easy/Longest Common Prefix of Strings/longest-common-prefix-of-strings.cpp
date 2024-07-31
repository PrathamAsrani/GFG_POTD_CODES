//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        string ans = "";
        int n = arr.size(), len = arr[0].size();
        int idx = 0;
        for(int i = 0; i < len; i++){
            char c = arr[0][idx];
            bool flag = true;
            for(int j = 0; j < n; j++){
                if(arr[j].size() <= idx || arr[j][idx] != c){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans += c;
            else 
                break;
            idx++;
        }
        return ans == "" ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends