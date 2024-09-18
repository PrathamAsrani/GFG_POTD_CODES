//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    int cycles = n-1;
	    vector<int> dis(n, 1e5);
	    dis[0] = 0;
	    while(cycles--){
	        for(auto &edge: edges){
	            int u = edge[0], v = edge[1], wei = edge[2];
	            if(dis[v] > dis[u] + wei){
	                dis[v] = dis[u] + wei;
	            }
	        }
	    }
	    for(auto &edge: edges){
	        int u = edge[0], v = edge[1], wei = edge[2];
	        if(dis[v] > dis[u] + wei){
	            return 1;
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends