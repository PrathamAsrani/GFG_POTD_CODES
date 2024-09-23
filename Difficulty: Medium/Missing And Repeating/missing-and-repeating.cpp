//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int hash[n+1] = {0};
        for(int &x: arr){
            hash[x]++;
        }
        int miss = -1, rep = -1;
        for(int i = 1; i <= n; i++){
            if(hash[i] == 2) rep = i;
            if(hash[i] == 0) miss = i;
        }
        return {rep, miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends