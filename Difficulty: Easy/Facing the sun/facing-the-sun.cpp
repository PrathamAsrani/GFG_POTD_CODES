//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int n = height.size();
        vector<int> prevGreater(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] < height[i]){
                st.pop();
            }
            if(!st.empty())
                prevGreater[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int &x: prevGreater)
            if(x == -1) ans++;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends