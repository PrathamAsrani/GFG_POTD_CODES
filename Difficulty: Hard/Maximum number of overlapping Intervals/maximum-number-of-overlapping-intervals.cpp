//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int overlap(vector<pair<int,int>>arr, int n){
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> ends;
        int ans = 0;
        for(auto &itr: arr){
            ends.push(itr.second);
            while(itr.first > ends.top())
                ends.pop();
            ans = max(ans,(int) ends.size());
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
	    int n;
	    cin >> n;
	    vector<pair<int,int>>intervals;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        intervals.push_back({a, b});
	    }
	    Solution ob;
	    int ans = ob.overlap(intervals, n);
	    cout << ans <<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends