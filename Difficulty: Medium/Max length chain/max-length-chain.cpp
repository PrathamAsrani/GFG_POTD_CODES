//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    vector<vector<int>> dp;
    int fun(struct val p[], int i, int &n, int prev = -1){
        if(i == n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int notTake = fun(p, i+1, n, prev);
        int take = 0;
        if(prev == -1 || p[prev].second < p[i].first){
            take = 1 + fun(p, i+1, n, i);
        }
        return dp[i][prev+1] = max(take, notTake);
    }
    
    int LB(vector<val> &dp, val p){
        int i = 0, j = dp.size()-1;
        while(i <= j){
            int mid = (i+j)/2;
            if(dp[mid].second <= p.second){
                i = mid+1;
            } else {
                j = mid-1;
            }
        }
        return i;
    }
    
    int maxChainLen(struct val p[], int n){
        //Your code here
        
        /*
        // MLE
        dp.assign(n, vector<int>(n+1, -1));
        sort(p, p + n, [&](val &a, val &b){
            return a.first < b.first;
        });
        return fun(p, 0, n);
        */
        
        /*
        // tle
        sort(p, p + n, [&](val &a, val &b){
            return a.first < b.first;
        });
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(p[i].first > p[j].second && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
        */
        
        sort(p, p + n, [&](val &a, val &b){
            return a.second < b.second;
        });
        vector<val> dp = {p[0]};
        for(int i = 1; i < n; i++){
            if(dp.back().second < p[i].first){
                dp.push_back(p[i]);
            } else{
                int idx = LB(dp, p[i]);
                dp[idx] = p[i];
            }
        }
        return dp.size();
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends