//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    vector<string> ans;
    vector<vector<bool>> vis;
    int n, m;
    int delX[4] = {0, -1, 0, 1};
    int delY[4] = {-1, 0, 1, 0};
    
    void dfs(int i, int j, vector<vector<int>> &mat, string path = ""){
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || mat[i][j] == 0) return ;
        if(i == n-1 && j == m-1){
            ans.push_back(path);
            return ;
        }
        vis[i][j] = true;
        for(int k = 0; k < 4; k++){
            int x = i + delX[k];
            int y = j + delY[k];
            char dir;
            if(k == 0) dir = 'L';
            if(k == 1) dir = 'U';
            if(k == 2) dir = 'R';
            if(k == 3) dir = 'D';
            dfs(x, y, mat, path+dir);
        }
        vis[i][j] = false;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        n = mat.size(), m = mat[0].size();
        vis.resize(n, vector<bool>(m, false));
        dfs(0, 0, mat);
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends