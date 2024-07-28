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
        if(s == t) return true;
        if(s.size() != t.size()) return false;
        if(dp.find(s+t) != dp.end()) return dp[s+t];
        
        int n = s.size();
        for(int i = 1; i < n; i++){
            bool swapped = isScramble(s.substr(0, i), t.substr(n-i, i)) && isScramble(s.substr(i, n-i), t.substr(0, n-i));
            if(swapped)
                return dp[s+t] = true;
            bool notSwapped = isScramble(s.substr(0, i), t.substr(0, i)) && isScramble(s.substr(i, n-i), t.substr(i, n-i));
            if(notSwapped)
                return dp[s+t] = true;
        }
        return dp[s+t] = false;
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