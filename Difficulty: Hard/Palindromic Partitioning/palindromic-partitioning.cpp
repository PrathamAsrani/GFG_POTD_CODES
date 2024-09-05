//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string str, int left, int right){
        while(left <= right) if(str[left++] != str[right--]) return false;
        return true;
    }
    
    void helper(int index, string str, vector<string> &sub, vector<vector<string>> &array){
        if(index >= str.size()){
            array.push_back(sub);
            return ;
        }
        for(int i = index; i < str.size(); i++){
            if(isPalindrome(str, index, i) == true){
                sub.push_back(str.substr(index, i-index+1));
                helper(i+1, str, sub, array);
                sub.pop_back();
            }
        }
    }
    
    int func(string String, int i, int j)
    {
        if (i >= j || isPalindrome(String, i, j)) return 0;
     
        int ans = INT_MAX, count;
        for (int k = i; k < j; k++) {
            count = func(String, i, k)
                    + func(String, k + 1, j) + 1;
            ans = min(ans, count);
        }
        return ans;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        // return func(str, 0, str.size()-1);
        
        /*
        vector<vector<string>> array;
        vector<string> sub;
        helper(0, str, sub, array);
        int ans= INT_MAX;
        for(auto i:array) if(i.size() < ans) ans = i.size();
        return ans-1;
        */
        
        
        int n = str.size();
        vector<int>dp(n+1,0);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--)
        {
            int mini = INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(str, i, j))
                {
                    int cut = 1 + dp[j+1];
                    mini = min(mini, cut);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends