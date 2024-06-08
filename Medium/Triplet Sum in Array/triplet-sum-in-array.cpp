//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        for(int i = 0; i < n; i++){
            if(arr[i] > X) continue;
            int x = X-arr[i];
            unordered_map<int, int> umpp;
            for(int j = i+1; j < n; j++){
                if(umpp.find(x - arr[j]) != umpp.end()) return true;
                else umpp[arr[j]]++;
            }
        }
        return 0;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends