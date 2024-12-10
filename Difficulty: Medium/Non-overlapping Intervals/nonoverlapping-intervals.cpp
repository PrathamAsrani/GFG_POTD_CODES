//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int ans = 0, left = 0, right = 1, n = arr.size();
        while(right < n){
            if(arr[right][0] >= arr[left][1]) 
                left = right; // non overlapping case
            else if(arr[right][1] >= arr[left][1])
                ans++; // delete right interval
            else if(arr[left][1] > arr[right][1])
                left = right, ans++; // delete left interval
            right++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends