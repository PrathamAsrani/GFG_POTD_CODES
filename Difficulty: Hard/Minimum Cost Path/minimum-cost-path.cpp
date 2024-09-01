//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class ds{
    public:
        int u, v, cost;
        ds(int c, int i, int j) : u(i), v(j), cost(c) {}
};

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        auto cmp = [](ds &a, ds &b) {return a.cost > b.cost; };
        priority_queue<ds, vector<ds>, decltype(cmp)> pq(cmp);
        dp[0][0] = grid[0][0];
        pq.push(ds(grid[0][0], 0, 0));
        int del[5] = {0, -1, 0, 1, 0};
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int i = it.u, j = it.v;
            if(i == n-1 && j == m-1) return it.cost;
            for(int k = 0; k < 4; k++){
                int x = i + del[k];
                int y = j + del[k+1];
                if(x >= 0 && x < n && y >= 0 && y < m){
                    int cost = it.cost + grid[x][y];
                    if(dp[x][y] > cost){
                        dp[x][y] = cost;
                        pq.push(ds(cost, x, y));
                    }
                }
            }
        }
        return dp[n-1][m-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends