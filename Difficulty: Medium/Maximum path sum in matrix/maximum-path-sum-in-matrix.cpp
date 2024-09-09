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
        vector<int> dp(n, 0), curr;
        for(int i = 0; i < n; i++){
            curr.assign(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0) curr[j] = grid[i][j];
                else{
                    int a = (j > 0) ? dp[j-1] : 0;
                    int b = dp[j];
                    int c = (j+1 < n) ? dp[j+1] : 0;
                    curr[j] = max({a, b, c}) + grid[i][j];
                }
            }
            dp = curr;
        }
        return *max_element(dp.begin(), dp.end());
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