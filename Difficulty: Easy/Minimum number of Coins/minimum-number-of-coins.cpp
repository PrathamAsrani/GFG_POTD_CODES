//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int sum)
    {
        /*
        vector<int> arr = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> dp(sum+1, 1e9);
        dp[0] = 0;
        int n = arr.size();
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(sum+1, 1e9);
            curr[0] = 0;
            for(int j = 0; j <= sum; j++){
                int notTake = dp[j], take = 1e9;
                if(j >= arr[i])
                    take = 1 + curr[j-arr[i]];
                curr[j] = min(take, notTake);
            }
            dp = curr;
        }
        return dp;
        */
        vector<int> arr = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 }, ans;
        int i = arr.size()-1;
        while(sum > 0){
            if(arr[i] <= sum){
                int cnt = sum/arr[i];
                while(cnt--) 
                    ans.push_back(arr[i]);
                sum = sum%arr[i];
            }
            i--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends