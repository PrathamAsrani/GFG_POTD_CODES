//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int dp[101][101];
    int fun(int i, int j, string &a, string &b, string &c){
        int k = i+j;
        if(i == a.size() && j == b.size() && k == c.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i < a.size() && a[i] == c[k] && fun(i+1, j, a, b, c)){
            return dp[i][j] = 1;
        }
        if(j < b.size() && b[j] == c[k] && fun(i, j+1, a, b, c)){
            return dp[i][j] = 1;
        }
        return dp[i][j] = 0;
    }
  public:
    /*You are required to complete this method */
    bool isInterleave(string &A, string &B, string &C) 
    {
        //Your code here
        if(A.size() + B.size() != C.size()) return 0;
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, A, B, C);
    }
};


//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends