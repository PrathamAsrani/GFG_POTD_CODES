//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class dsu{
public:
    vector<int> par, sz;
    dsu(int n){
        par.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    
    int Find(int node){
        return node == par[node] ? node : par[node] = Find(par[node]);
    }
    
    void Unite(int a, int b){
        int pa = Find(a), pb = Find(b);
        if(pa == pb) return ;
        if(sz[pa] >= sz[pb]){
            sz[pa] += sz[pb];
            par[pb] = pa;
        } else {
            sz[pb] += sz[pa];
            par[pa] = pb;
        }
    }
};

bool isSafe(int i, int j, int n, int m){
    return i >= 0 && i < n && j >= 0 && j < m;
}

class Solution {
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dsu d(n * m);
        
        int delX[4] = {0, -1, 0, 1};
        int delY[4] = {-1, 0, 1, 0};
        
        // Build DSU for all 1s
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k < 4; k++) {
                        int ni = i + delX[k];
                        int nj = j + delY[k];
                        if(isSafe(ni, nj, n, m) && grid[ni][nj] == 1) {
                            d.Unite(i * m + j, ni * m + nj);
                        }
                    }
                }
            }
        }
        
        int maxConnected = *max_element(d.sz.begin(), d.sz.end());
        
        // Check each 0 cell
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    int combinedSize = 1;
                    set<int> uniqueParents;
                    for(int k = 0; k < 4; k++) {
                        int ni = i + delX[k];
                        int nj = j + delY[k];
                        if(isSafe(ni, nj, n, m) && grid[ni][nj] == 1) {
                            int parent = d.Find(ni * m + nj);
                            if(uniqueParents.find(parent) == uniqueParents.end()) {
                                uniqueParents.insert(parent);
                                combinedSize += d.sz[parent];
                            }
                        }
                    }
                    maxConnected = max(maxConnected, combinedSize);
                }
            }
        }
        
        return maxConnected;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends