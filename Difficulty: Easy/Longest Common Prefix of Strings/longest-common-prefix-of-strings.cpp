//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        int n = arr.size();
        if(!n) return "-1";
        else if(n == 1) return arr[0];
        sort(arr.begin(), arr.end());
        int leng = min(arr[0].size(), arr[n-1].size()), i = 0, cnt = 0;
        while(i < leng && arr[0][i] == arr[n-1][i]) cnt++, i++;
        return (cnt)? arr[0].substr(0, cnt):"-1";
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