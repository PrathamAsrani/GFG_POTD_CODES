//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int l = 0, d = mat.size()-1, u = 0, r = mat[0].size()-1;
        vector<int> ans;
        while(l <= r and u <= d){
            // fetch upper row
            for(int i = l; i <= r; i++) ans.push_back(mat[u][i]);
            u++;
            for(int i = u; i <= d; i++) ans.push_back(mat[i][r]);
            r--;
            if(u <= d){
                for(int i = r; i >= l; i--) ans.push_back(mat[d][i]);
                d--;
            }
            if(l <= r){
                for(int i = d; i >= u; i--) ans.push_back(mat[i][l]);
                l++;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends