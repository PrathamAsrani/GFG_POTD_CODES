//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        vector<int> dp(sum+1, 0);
        int mod = 1e9+7;
        dp[0] = 1;
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(sum+1, 0);
            curr[0] = 1;
            for(int j = 0; j <= sum; j++){
                int notTake = dp[j];
                int take = 0;
                if(j >= arr[i])
                    take = dp[j-arr[i]];
                curr[j] = (take+notTake)%mod;
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
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends