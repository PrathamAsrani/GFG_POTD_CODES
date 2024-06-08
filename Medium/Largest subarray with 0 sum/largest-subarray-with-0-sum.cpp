//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        /*
        int ans = 0;
        for(int i = 0, j; i < n; i++){
            int sum = arr[i];
            for(j = i+1; j < n; j++){
                if(sum == 0) ans = max(ans, j-i);
                sum += arr[j];
            }
            if(sum == 0) ans = max(ans, j-i);
        }
        return ans;
        */
        
        unordered_map<int, int> umpp;
        umpp[0] = -1;
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(umpp.find(sum) != umpp.end()){
                ans = max(ans, i-umpp[sum]);
            }
            else umpp[sum] = i;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends