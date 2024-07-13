//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
    // Write your code here

class Solution{
    public:
    int mergeNsort(int a[], int b[], int n, int m, int answer[])
    {
        int dp[100001];
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++) dp[a[i]] = 1;
        for(int i = 0; i < m; i++) dp[b[i]] = 1;
        
        for(int i = 0; i < 100001; i++){
            if(dp[i] != -1){
                cout << i << " ";
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>m;
        int b[m+5];
        for(int j=0;j<m;j++)
            cin>>b[j];
        Solution ob;
        int answer[n+m+5];
        int x=ob.mergeNsort(a, b, n, m, answer);
        
        for(int i=0;i<x;i++)
        cout<<answer[i]<<" ";
        cout<<endl;
    }
	
	return 0;
}
// } Driver Code Ends