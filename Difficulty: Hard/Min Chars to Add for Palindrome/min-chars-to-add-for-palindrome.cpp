//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    int prefix(string &s){
        int n = s.size();
        int pi[n];
        fill_n(pi, n, 0);
        for(int i = 1; i < n; i++){
            int prev = pi[i-1];
            while(prev > 0 && s[prev] != s[i]){
                prev = pi[prev-1];
            }
            if(s[prev] == s[i]){
                prev++;
            }
            pi[i] = prev;
        }
        return pi[n-1];
    }
public:
    int minChar(string str){
        //Write your code here
        string rev = str;
        reverse(rev.begin(), rev.end());
        string s = str + "$" + rev;
        return str.size() - prefix(s);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends