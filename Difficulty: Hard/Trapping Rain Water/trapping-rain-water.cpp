//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

typedef long long ll;

class Solution{
    // Function to find the trapped water between the blocks.
    public:
    ll trappingWater(int arr[], int n){
        /*
        ll ans = 0;
        for(int i = 1; i < n-1; i++){
            int left = arr[i];
            for(int j = 0; j < i; j++){
                left = max(left, arr[j]);
            }
            
            int right = arr[i];
            for(int j = i+1; j < n; j++){
                right = max(right, arr[j]);
            }
            
            ans += (min(left, right)-arr[i]);
        }
        return ans;
        */
        
        ll ans = 0;
        int l[n], r[n];
        l[0] = arr[0], r[n-1] = arr[n-1];
        for(int i = 1; i < n; i++) l[i] = max(arr[i], l[i-1]);
        for(int i = n-2; i >= 0; i--) r[i] = max(r[i+1], arr[i]);
        for(int i = 0; i < n; i++){
            ans += min(l[i], r[i])-arr[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends