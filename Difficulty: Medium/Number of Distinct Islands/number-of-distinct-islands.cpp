//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int del[5] = {0, -1, 0, 1, 0};
    set<vector<pair<int, int>>> distinctIslands;
    int n, m;
    vector<vector<bool>> vis;
    
    
    
    
    void dfs(int baseRow, int baseCol, int i, int j, vector<vector<int>> &grid, vector<pair<int, int>> &island){
        vis[i][j] = 1;
        int row = baseRow - i, col = baseCol - j;
        island.push_back({row, col});
        
        for(int k = 1; k < 5; k++){
            int x = i + del[k-1];
            int y = j + del[k];
            if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == 1){
                dfs(baseRow, baseCol, x, y, grid, island);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        n = grid.size(), m = grid[0].size();
        vis.resize(n, vector<bool>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int, int>> island;
                    dfs(i, j, i, j, grid, island);
                    distinctIslands.insert(island);
                }
            }
        }
        return distinctIslands.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends