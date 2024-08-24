//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long int lli;

class Solution {
public:
	long long int closestPalindrome(long long int num){
	    // Code here
	    if(num < 10) return num;
	    string number = to_string(num);
	    
	    // create palindrome of len-1 e.g. if num is 100 then 99 will be pushed
	    // create palindrome of len e.g. if num is 100 then 1001 will be pushed
	    int n = number.size();
	    vector<lli> candidates = { pow(10, n-1)-1, pow(10, n)+1 };
	    
	    string half = number.substr(0, (n+1)/2);
	    lli prefix = stoll(half);
	    vector<lli> prefexes = { prefix-1, prefix, prefix+1 };
	    
	    for(auto &p: prefexes){
	        string left = to_string(p);
	        string right = left;
	        if(n&1) right.pop_back();
	        reverse(right.begin(), right.end());
	        candidates.push_back(stoll(left+right));
	    }
	    
	    lli closet = 0, mini = 1e18;
	    for(auto &cand: candidates){
	        lli diff = abs(cand - num);
	        if(diff < mini){
	            closet = cand;
	            mini = diff;
	        } else if(diff == mini){
	            closet = min(closet, cand);
	        }
	    }
	    return closet;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends