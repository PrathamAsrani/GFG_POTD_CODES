//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class ds{
    public:
        int key, val;
        ds(int x = 0, int y = 0): key(x), val(y) {};
};

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    ds arr[n];
	    for(int i = 0; i < n; i++){
	        arr[i].key = i;
	        arr[i].val = nums[i];
	    }
	    sort(arr, arr+n, [&](ds &a, ds &b){
	        return a.val < b.val;
	    });
	   // for(int i = 0; i < n; i++)
	   //     cout << arr[i].key << " " << arr[i].val << "\n";
	   int swaps = 0, cycle_len = 0, j = 0;
	   bool vis[n];
	   for(int i = 0; i < n; vis[i] = false, i++);
	   for(int i = 0; i < n; i++){
	       if(i == arr[i].key || vis[i]) continue;
	       //cout << i << " " << arr[i].key << " " << arr[i].val << "\n";
	       j = arr[i].key;
	       cycle_len = 0;
	       while(j != i){
	           vis[j] = true;
	           j = arr[j].key;
	           cycle_len++;
	       }
	       //cout << cycle_len << "\n";
	       swaps += cycle_len;
	   }
	   return swaps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends