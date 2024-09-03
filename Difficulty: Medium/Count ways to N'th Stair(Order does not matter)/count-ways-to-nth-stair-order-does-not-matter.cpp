//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthStair(int n, int use = 1){
		    //  Code here
		    if(n == 0) return 1;
		    if(n < 0) return 0;
		    int ways = 0;
		    if(use == 1){
		        ways = nthStair(n-use, use) + nthStair(n-2, 2);
		    } else {
		        ways = nthStair(n-use, use);
		    }
		    return ways;
		} 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends