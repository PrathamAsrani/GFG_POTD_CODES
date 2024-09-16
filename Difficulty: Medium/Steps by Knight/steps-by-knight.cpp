//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;
	    vector<vector<bool>> vis(n, vector<bool>(n, 0));
	    queue<pair<int, int>> q;
	    q.push({KnightPos[0]-1, KnightPos[1]-1});
	    vis[KnightPos[0]-1][KnightPos[1]-1] = true;
	    int delX[8] = {1, 1, -1, -1, 2, 2, -2, -2};
	    int delY[8] = {2, -2, 2, -2, 1, -1, 1, -1};
	    int lvl = 0;
	    while(!q.empty()){
	        int sz = q.size();
	        while(sz--){
	            int i = q.front().first, j = q.front().second;
	            q.pop();
	            if(i == tx && j == ty) return lvl;
	            for(int k = 0; k < 8; k++){
	                int x = i + delX[k];
	                int y = j + delY[k];
	                if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]){
	                    q.push({x, y});
	                    vis[x][y] = true;
	                }
	            }
	        }
	        lvl++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends