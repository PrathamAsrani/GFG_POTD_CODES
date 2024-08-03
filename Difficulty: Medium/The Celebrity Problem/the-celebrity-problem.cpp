//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> inDeg(n, 0), outDeg(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]) 
                    inDeg[j]++, outDeg[i]++;
            }
        }
        int cele = -1;
        for(int i = 0; i < n; i++){
            if(cele == -1 and inDeg[i] == n-1 && outDeg[i] == 0)
                cele = i;
            else if(cele != -1 and inDeg[i] == n-1 && outDeg[i] == 0) 
                return -1;
        }
        return cele;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends