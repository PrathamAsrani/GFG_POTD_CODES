//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long maximizeVolume(long long S) {
        /*
        long long ans = 0;
        for(int l = 1; l <= S-2; l++){
            for(int b = 1; b <= S-1; b++){
                int h = S-l-b;
                ans = max(ans, (long long) l*b*h);
            }
        }
        return ans;
        */
        
        int l = S/3;
        S -= l;
        int b = S/2;
        S -= b;
        int h = S/1;
        S -= h;
        
        return (long long) l*b*h;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long S;
        
        cin>>S;

        Solution ob;
        cout << ob.maximizeVolume(S) << endl;
    }
    return 0;
}
// } Driver Code Ends