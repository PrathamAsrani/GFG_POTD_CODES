//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

template <typename T>
T mini(T a, T b){
    return a < b ? a : b;
}

long long maxArea(long long arr[], int n)
{
    /*
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j  = i+1; j < n; j++){
            long long val = ((j-i) * mini(arr[i], arr[j]));
            if(val > ans)
                ans = val;
        }
    }
    return ans;
    */
    
    long long ans = 0;
    int i = 0, j = n-1;
    while(i < j){
        long long val = (j-i) * mini(arr[i], arr[j]);
        if(val > ans) 
            ans = val;
         
        if(arr[i] >= arr[j]){
            j--;
        } else {
            i++;
        }
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends