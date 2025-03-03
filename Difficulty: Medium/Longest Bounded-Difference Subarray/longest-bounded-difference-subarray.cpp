//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size(), ans = 0;
        if(n <= 0) 
            return {};
        int mini = arr[0], maxi = arr[0];
        int start = -1, end = -1;
        for(int i = 0, j = 0; j < n; j++){
            mini = min(mini, arr[j]);
            maxi = max(maxi, arr[j]);
            // cout << "debug: " << maxi << " " << mini << "\n";
            if(maxi-mini > x){
                while(i <= j && arr[i] != mini && arr[i] != maxi){
                    i++;
                }
                maxi = mini = arr[++i];
                j = i;
            }
            if(j-i+1 > ans){
                // cout << i << " " << j << "\n";
                ans = j-i+1;
                end = j;
                start = i;
            }
            // cout << "ans: " << ans << "\n";
        }
        // cout << start << " " << end << "\n";
        if(start == -1)
            return {arr[0]};
        return vector<int>(arr.begin() + start, arr.begin() + end + 1);
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends