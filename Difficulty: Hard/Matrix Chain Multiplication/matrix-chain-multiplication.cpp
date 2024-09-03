//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[101][101];
    int fun(int i, int j, int arr[]){
        // base case: Single matrix left
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int multiplications = 1e9;
        // create partition for pairs of matrix
        /*
        mat1: 10*20
        mat2: 20*5
        therefore, mat1 * mat2 => 10*20*5 where arr[i-1] = 10, arr[k] = 20, and arr[j] = 5
        */
        for(int k = i; k < j; k++){
            multiplications = min(multiplications, 
                (arr[i-1] * arr[k] * arr[j]) + fun(i, k, arr) + fun(k+1, j, arr));
        }
        return dp[i][j] = multiplications;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        // pass the full block
        return fun(1, N-1, arr);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends