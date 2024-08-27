//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    vector<int> getPrevMini(vector<int> &arr){
        int n = arr.size();
        vector<int> dp(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] <= st.top()) 
                st.pop();
            if(!st.empty()) dp[i] = st.top();
            st.push(arr[i]);
        }
        return dp;
    }
    vector<int> getNextMini(vector<int> &arr){
        int n = arr.size();
        vector<int> dp(n, 0);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] <= st.top()) 
                st.pop();
            if(!st.empty()) dp[i] = st.top();
            st.push(arr[i]);
        }
        return dp;
    }
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> prev = getPrevMini(arr);
        vector<int> next = getNextMini(arr);
        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, abs(prev[i] - next[i]));
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends