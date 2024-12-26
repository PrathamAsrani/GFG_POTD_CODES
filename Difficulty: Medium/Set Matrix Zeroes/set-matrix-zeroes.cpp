//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<bool> row(n, 0), col(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int r = 0; r < n; r++){
            if(row[r] == true){
                for(int i = 0; i < m; i++){
                    mat[r][i] = 0;
                }
            }
        }
        for(int c = 0; c < m; c++){
            if(col[c] == true){
                for(int i = 0; i < n; i++){
                    mat[i][c] = 0;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends