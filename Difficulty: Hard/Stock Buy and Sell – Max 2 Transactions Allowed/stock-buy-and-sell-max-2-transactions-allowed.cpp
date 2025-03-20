//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n <= 0)
            return 0;
        vector<int> pf(n), sf(n);
        int val = arr[0];
        for(int i = 1; i < n; i++)
            pf[i] = max(pf[i-1], arr[i] - val), val = min(val, arr[i]);
        val = arr[n-1];
        for(int i = n-2; i >= 0; i--)
            sf[i] = max(sf[i+1], val - arr[i]), val = max(val, arr[i]);
        val = 0;
        for(int i = 0; i < n; i++)
            val = max(val, pf[i] + sf[i]);
        return val;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends