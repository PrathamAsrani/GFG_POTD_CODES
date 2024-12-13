//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void helper(vector<int> &arr, int l, int r, int &mini){
        if(l > r) return ;
        if(l == r) {
            if(mini > arr[l]){
                mini = arr[l];
            }
            return ;
        }
        
        int mid = l+(r-l)/2;
        helper(arr, l, mid, mini);
        helper(arr, mid+1, r, mini);
    }
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int n = arr.size(), mini = 1e9;
        helper(arr, 0, n-1, mini);
        return mini;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends