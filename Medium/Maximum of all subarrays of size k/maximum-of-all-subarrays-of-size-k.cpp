//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        /*
        multiset<int> ms;
        for(int i = 0; i < k; i++) ms.insert(arr[i]);
        vector<int> ans = {*ms.rbegin()};
        for(int i = k; i < n; i++){
            ms.erase(ms.find(arr[i-k]));
            ms.insert(arr[i]);
            ans.push_back(*ms.rbegin());
        }
        return ans;
        */
        
        /*
        vector <int> ans;
        for(int i = 0; i <= n-k; i++){
            int maxi = arr[i];
            for(int j = 1; j < k; j++){
                maxi = max(maxi, arr[i+j]);
            }
            ans.push_back(maxi);
        }
        return ans;
        */
        
        deque<int> dq;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && arr[i] >= arr[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        vector<int> ans;
        for(int i = k; i < n; i++){
            ans.push_back(arr[dq.front()]);
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
            while(!dq.empty() && arr[i] >= arr[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends