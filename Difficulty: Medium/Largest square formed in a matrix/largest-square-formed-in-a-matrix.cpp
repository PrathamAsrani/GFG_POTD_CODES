//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dis(vector<vector<int>> arr){
        int n = arr.size(), m = arr[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        /*
        vector<vector<int>> row(n, vector<int>(m, 0)), col(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j == 0) row[i][j] = mat[i][j];
                else row[i][j] += mat[i][j] == 1 ? 1+row[i][j-1] : 0;
            }
        }
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(i == 0) col[i][j] = mat[i][j];
                else col[i][j] += mat[i][j] == 1 ? 1+col[i-1][j] : 0;
            }
        }
        
        int ans = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int mini = min(row[i][j], col[i][j]);
                while(mini > ans){
                    if(row[i-mini+1][j] >= mini and col[i][j-mini+1] >= mini) {
                        ans = mini;
                        break;
                    }
                    mini--;
                }
            }
        }
        return ans;
        */
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSize = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = mat[i][j];
                } else if (mat[i][j] == 1) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                } else {
                    dp[i][j] = 0;
                }
                maxSize = max(maxSize, dp[i][j]);
            }
        }
        
        return maxSize;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends