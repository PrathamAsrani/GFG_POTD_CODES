//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i = 1; i <= sum; i++) dp[n][i] = 0;
        dp[n][0] = 1; // at last sum becomes 0
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= sum; j++){
                int a = dp[i+1][j];
                int b = 0;
                if(arr[i] <= j) b = dp[i+1][j-arr[i]];
                dp[i][j] = (a+b)%mod;
            }
        }
        return dp[0][sum];
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