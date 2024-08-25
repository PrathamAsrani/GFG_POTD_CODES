//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    unordered_map<string, bool> dp;
    public:
    bool isScramble(string s, string t){
        //code here
        if(s == t) return 1; // O(N)
        int n = s.size();
        if(n == 1) return 0;
        
        string key = s + " " + t; // O(N)
        if(dp.find(key) != dp.end()) return dp[key]; // O(N)
        
        for(int i = 1; i < n; i++){
            if(isScramble(s.substr(0, i), t.substr(0, i)) 
                && isScramble(s.substr(i), t.substr(i))){
                    return dp[key] = true;
                }
            if(isScramble(s.substr(0, i), t.substr(n-i)) 
                && isScramble(s.substr(i), t.substr(0, n-i))){
                    return dp[key] = true;
                }
        }
        return dp[key] = false;
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends