//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef long long ll;

class Solution {
    vector<vector<char>> kb = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}
    };
    
    int delX[5] = {0, 0, -1, 0, 1};
    int delY[5] = {0, -1, 0, 1, 0};
    
    ll helper(int i, int j, int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        
        ll val = 0;
        for (int k = 0; k < 5; k++) {
            int row = i + delX[k];
            int col = j + delY[k];
            if (row >= 0 && row < 4 && col >= 0 && col < 3 && kb[row][col] != '*' && kb[row][col] != '#') {
                val += helper(row, col, n - 1);
            }
        }
        return val;
    }
    
  public:
  
    ll getCount(int N) {
        /*
        if(n <= 0) return 0;
        if(n == 1) return 10;
        ll ans = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(kb[i][j] != '*' && kb[i][j] != '#'){
                    ans += helper(i, j, n);
                }
            }
        }
        return ans;
        */
        
        long dp[N + 1][10];
 
        vector<vector<int> > data
            = { { 0, 8 },          { 1, 2, 4 },
                { 1, 2, 3, 5 },    { 2, 3, 6 },
                { 1, 4, 5, 7 },    { 2, 4, 5, 6, 8 },
                { 3, 5, 6, 9 },    { 4, 7, 8 },
                { 5, 7, 8, 9, 0 }, { 6, 8, 9 } };
    
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= 9; j++) {
                if (i == 1)
                    dp[i][j] = 1;
                else {
                    dp[i][j] = 0;
                    for (int k = 0; k < data[j].size(); k++)
                        dp[i][j] += dp[i - 1][data[j][k]];
                }
            }
        }
        long sum = 0;
        for (int j = 0; j <= 9; j++) {
            sum += dp[N][j];
        }
        return sum;
    }
};  


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends