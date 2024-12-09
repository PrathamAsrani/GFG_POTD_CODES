//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &arr,
                                       vector<int> &ni) {
        // code here
        int n = arr.size();
        vector<vector<int>> ans;
        if(n <= 0){
            return ans;
        }
        for(int i = 0; i < n; i++){
            if(ni[1] < arr[i][0]){
                ans.push_back(ni);
                for(i; i < n; i++)
                    ans.push_back(arr[i]);
                return ans;
            }
            else if(arr[i][1] < ni[0]){
                ans.push_back(arr[i]);
            }
            else {
                ni[0] = min(ni[0], arr[i][0]);
                ni[1] = max(ni[1], arr[i][1]);
            }
        }
        ans.push_back(ni);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends