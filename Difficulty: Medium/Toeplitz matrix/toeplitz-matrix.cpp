//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

bool isToepliz(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    for(int i = 0; i < n; i++){
        int x = i, y = 0, val = mat[x][y];
        while(x < n and y < m){
            if(val != mat[x][y]) 
                return false;
            x++, y++;
        }
    }
    for(int i = 1; i < m; i++){
        int x = 0, y = i, val = mat[x][y];
        while(x < n and y < m){
            if(val != mat[x][y]) 
                return false;
            x++, y++;
        }
    }
    return true;
}

