//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string &s, string &p)
    {
        // Your code here
        int hash[256] = {0};
        int cnt = 0;
        for(char &c: p){
            if(hash[c] == 0)
                cnt++;
            hash[c]++;
        }
        int start = 0, i = 0, len = 1e9;
        for(int j = 0; j < s.size(); j++){
            hash[s[j]]--;
            if(hash[s[j]] == 0){
                cnt--;
            }
            while(cnt == 0){
                if(j-i+1 < len){
                    len = j-i+1;
                    start = i;
                }
                hash[s[i]]++;
                if(hash[s[i]] == 1){
                    cnt++;
                }
                i++;
            }
        }
        return len == 1e9 ? "-1" : s.substr(start, len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends