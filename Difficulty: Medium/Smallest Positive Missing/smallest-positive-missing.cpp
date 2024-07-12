//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        /*
        // O(N2)
        int temp = 1;
        for(int i = 0; i < n; i++){
            if(arr[i] == temp){
                i = -1;
                temp++;
            }
        }
        return temp;
        */
        /*
        set<int> s;
        for(int i = 0 ; i < n; i++){
            if(arr[i] > 0){
                s.insert(arr[i]);
            }
        }
        set<int>::iterator i = s.begin();
        i++;
        int temp = 0;
        for(auto itr:s){
            int a = itr;
            temp = *i;
            i++;
            if(temp-a != 1)return a+1;
        }
        return temp+1;
        */
        
        /*
        for(int i = 0; i < n; i++){
            int t = arr[i]-1;
            while(arr[i] > 0 && arr[i] <= n && arr[i]!=arr[t]){
                swap(arr[t], arr[i]);
                t = arr[i]-1;
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] != i+1) return i+1;
        }
        return n+1;
        */
        
        for(int i = 0; i < n; i++)
            if(arr[i] <= 0 || arr[i] > n)
                arr[i] = n+1;
        
        for(int i = 0; i < n; i++){
            int idx = abs(arr[i]);
            if(idx >= 1 and idx <= n and arr[idx-1] > 0){
                arr[idx-1] = -arr[idx-1];
            }
        }
        
        for(int i = 0; i < n; i++)
            if(arr[i] >= 0)
                return i+1;
        
        return n+1;
    } 
};


//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends