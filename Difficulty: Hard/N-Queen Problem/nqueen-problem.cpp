//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<int>> ans;
    void solve(int col, int &n, vector<int> &placed, vector<bool> &rows, vector<bool> &upperDiag, vector<bool> &lowerDiag){
        if(col == n){
            ans.push_back(placed);
            return ;
        }
        for(int row = 0; row < n; row++){
            if(!rows[row] && !upperDiag[col-row+n-1] && !lowerDiag[col+row]){
                rows[row] = upperDiag[col-row+n-1] = lowerDiag[row+col] = 1;
                placed.push_back(row+1);
                solve(col+1, n, placed, rows, upperDiag, lowerDiag);
                rows[row] = upperDiag[col-row+n-1] = lowerDiag[row+col] = 0;
                placed.pop_back();
            }
        }
    }
  public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<bool> row(n, false), upperDiag(2*n-1, false), lowerDiag(2*n-1, 0);
        vector<int> placed;
        solve(0, n, placed, row, upperDiag, lowerDiag);
        sort(ans.begin(), ans.end());
        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends