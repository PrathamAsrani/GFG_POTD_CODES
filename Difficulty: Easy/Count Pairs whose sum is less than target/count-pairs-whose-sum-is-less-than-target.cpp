//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    int binary_search(vector<int> &arr, int x){
        int low = 0, high = arr.size()-1;
        int idx = -1;
        while(low <= high){
           int mid = (low+high)/2;
           if(arr[mid] <= x){
               low = mid+1;
               idx = mid;
           }
           else high = mid-1;
        }
        return idx;
    }
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int ans = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            int x = target - arr[i] - 1;
            int idx = binary_search(arr, x);
            if(idx <= i)
                continue;
            ans += (idx - i);
        }
        return ans;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends