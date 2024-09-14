//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<int> dp(w+1, 0);
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(w+1, 0);
            for(int j = 0; j <= w; j++){
                int notTake = dp[j], take = 0;
                if(j >= wt[i])
                    take = curr[j-wt[i]] + val[i];
                curr[j] = max(take, notTake);
            }
            dp = curr;
        }
        return dp[w];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends