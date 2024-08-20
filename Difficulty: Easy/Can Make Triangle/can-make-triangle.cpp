//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> arr, int n){
        // code here
        vector<int> ans;
        for(int i = 2; i < n; i++){
            if(arr[i] < arr[i-1]+arr[i-2] && arr[i-1] < arr[i-2] + arr[i] && arr[i-2] < arr[i-1] + arr[i]) 
                ans.push_back(1);
            else 
                ans.push_back(0);
        }
        return ans;
    }
}; 

//{ Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
} 
// } Driver Code Ends