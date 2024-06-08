//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        unordered_map<int, int> umpp; int ans = n;
        for(int i = 0; i < n; i++){
            if(umpp.find(arr[i]) != umpp.end()){
                ans = min(ans, umpp[arr[i]]);
            }
            else umpp[arr[i]] = i;
        }
        return ans == n ? -1 : ans+1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends