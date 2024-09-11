//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<int> dp(sum+1, 0), curr;
        int n = arr.size();
        dp[0] = 1;
        for(int i = n-1; i >= 0; i--){
            curr.assign(sum+1, 0);
            curr[0] = 1;
            for(int j = 1; j <= sum; j++){
                int notTake = dp[j];
                int take = 0;
                if(j >= arr[i]){
                    take = dp[j-arr[i]];
                }
                curr[j] = take || notTake;
            }
            dp = curr;
        }
        return dp[sum];
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends