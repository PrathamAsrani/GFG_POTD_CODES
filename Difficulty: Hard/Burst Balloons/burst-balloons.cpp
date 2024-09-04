//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<vector<int>> dp;
    int fun(int i, int j, vector<int> &arr){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        for(int k = i; k <= j; k++){
            ans = max(ans, (arr[i-1] * arr[j+1] * arr[k]) + fun(i, k-1, arr) + fun(k+1, j, arr));
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(int n, vector<int> &arr) {
        // code here
        /*
        approach: Start in reverse manner, like who is the last guy that is burst
        ans += 1 * lastGuy * 1 
        then function call of (left, lastGuy-1) + (lastGuy+1, right) + arr[left-1] * arr[lastGuy] * arr[right+1]
        */
        arr.push_back(1);
        arr.insert(arr.begin(), 1);
        n = arr.size();
        dp.assign(n, vector<int>(n, -1));
        return fun(1, n-2, arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends