//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
  public:
    
    int extractMaximum(string s) 
    { 
        int ans = -1, num = 0;
        for(char &c: s){
            if(c >= '0' && c <= '9'){
                num = num*10 + c-'0';
                if(num > ans)
                    ans = num;
            }else{
                num = 0;
            }
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
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.extractMaximum(S)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends