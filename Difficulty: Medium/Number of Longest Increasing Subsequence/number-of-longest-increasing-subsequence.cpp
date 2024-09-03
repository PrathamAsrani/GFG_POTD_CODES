//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j]){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    } 
                    else if(dp[i] == dp[j]+1){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int ans = 0, lis = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] > lis){
                lis = dp[i];
                ans = cnt[i];
            } else if(dp[i] == lis){
                ans += cnt[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends