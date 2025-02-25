//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int n;
    vector<int> FindNextSmaller(vector<int> &arr){
        vector<int> res(n, n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty())
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> FindPrevSmaller(vector<int> &arr){
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty())
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        n = arr.size();
        vector<int> nextSmaller = FindNextSmaller(arr);
        vector<int> prevSmaller = FindPrevSmaller(arr);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, arr[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends