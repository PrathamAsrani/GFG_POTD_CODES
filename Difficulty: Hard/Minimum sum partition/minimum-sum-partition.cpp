//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i = 0; i < n; i++) sum += arr[i];
	    
	    vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
	    
	    for(int i = 0; i < n; i++) 
	        dp[i][0] = true;
	    
	    if(arr[0] <= sum) dp[0][arr[0]] = true;
	    for(int i = 1; i < n; i++){
	        for(int acc = 1; acc <= sum; acc++){
	            if(acc < arr[i]) dp[i][acc] = dp[i-1][acc];
	            else dp[i][acc] = dp[i-1][acc] || dp[i-1][acc-arr[i]];
	        }
	    }
	    
	    int ans = 1e9;
	    for(int i = sum/2; i >= 0; i--){
	        if(dp[n-1][i] == true){
	            ans = i;
	            break;
	        }
	    }
	    return abs((sum - ans) - ans);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends