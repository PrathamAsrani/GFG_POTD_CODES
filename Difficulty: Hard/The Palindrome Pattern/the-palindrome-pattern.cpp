//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        int n = arr.size();
        for(int row = 0; row < n; row++){
            int i = 0, j = n-1;
            while(i < j and arr[row][i] == arr[row][j])
                i++, j--;
            if(i >= j)
                return to_string(row) + " R";
        }
        for(int col = 0; col < n; col++){
            int i = 0, j = n-1;
            while(i < j and arr[i][col] == arr[j][col])
                i++, j--;
            if(i >= j)
                return to_string(col) + " C";
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends