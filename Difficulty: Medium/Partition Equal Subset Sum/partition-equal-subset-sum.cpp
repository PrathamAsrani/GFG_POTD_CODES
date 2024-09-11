//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    typedef long long ll;
public:
    int equalPartition(int n, int arr[])
    {
        ll total = accumulate(arr, arr+n, 0);
        if(total & 1) return 0;
        ll k = total/2;
        vector<bool> dp(k+1, 0);
        dp[0] = 1;
        for(int i = n-1; i >= 0; i--){
            vector<bool> curr(k+1, 0);
            curr[0] = 1;
            for(int j = 1; j <= k; j++){
                bool notTake = dp[j], take = 0;
                if(j >= arr[i]) 
                    take = dp[j - arr[i]];
                curr[j] = take | notTake;
            }
            dp = curr;
        }
        return dp[k];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends