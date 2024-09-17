//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size(), m = grid[0].size();
        int sr = -1, sc = -1, dr = -1, dc = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    sr = i, sc = j;
                    if(sr != -1 && dr != -1) break;
                }
                if(grid[i][j] == 2){
                    dr = i, dc = j;
                    if(sr != -1 && dr != -1) break;
                }
            }
            if(sr != -1 && dr != -1) break;
        }
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        q.push({sr, sc});
        vis[sr][sc] = 1;
        int lvl = 0;
        int delX[4] = {0, -1, 0, 1};
        int delY[4] = {-1, 0, 1, 0};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(i == dr && j == dc) return 1;
                for(int k = 0; k < 4; k++){
                    int x = i + delX[k];
                    int y = j + delY[k];
                    if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] != 0){
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            lvl++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends