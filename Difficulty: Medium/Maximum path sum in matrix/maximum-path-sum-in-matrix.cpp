//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> grid)
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0) dp[i][j] = grid[i][j];
                else{
                    int a = (j > 0) ? dp[i-1][j-1] : 0;
                    int b = dp[i-1][j];
                    int c = (j+1 < n) ? dp[i-1][j+1] : 0;
                    dp[i][j] = max({a, b, c}) + grid[i][j];
                }
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends