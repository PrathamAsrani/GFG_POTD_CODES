//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    int n;
    int GetMinOfMaxWnd(int &k, vector<int> &arr){
        int res = 0;
        for(int i = 0; i <= n-k; i++){
            int val = arr[i];
            for(int j = i; j < i+k; j++){
                val = min(val, arr[j]);
            }
            res = max(res, val);
        }
        return res;
    }
    vector<int> FindPrevSmaller(vector<int> &arr){
        stack<int> st;
        vector<int> res(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty())
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> FindNextSmaller(vector<int> &arr){
        stack<int> st;
        vector<int> res(n, n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty())
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        n = arr.size();
        /*
        vector<int> ans;
        for(int wnd = 1; wnd <= n; wnd++){
            ans.push_back(GetMinOfMaxWnd(wnd, arr));
        }
        return ans;
        */
        
        vector<int> prevSmaller = FindPrevSmaller(arr);
        vector<int> nextSmaller = FindNextSmaller(arr);
        vector<int> res(n+1, 0);
        for(int i = 0; i < n; i++){
            int wnd = nextSmaller[i] - prevSmaller[i] - 1;
            res[wnd] = max(res[wnd], arr[i]);
        }
        for(int i = n-1; i >= 1; i--){
            res[i] = max(res[i], res[i+1]);
        }
        res.erase(res.begin());
        return res;
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends