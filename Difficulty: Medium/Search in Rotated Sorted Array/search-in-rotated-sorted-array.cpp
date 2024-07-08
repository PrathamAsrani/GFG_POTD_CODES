//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int l, int r, vector<int>& arr, int key) {
        if(l > r) 
            return -1;
        int mid = (l+r)/2;
        if(arr[mid] == key)
            return mid;
        int left = helper(l, mid-1, arr, key);
        if(left != -1) {
            return left;
        }
        int right = helper(mid+1, r, arr, key);
        if(right != -1) {
            return right;
        }
        return -1;
    }
    int search(vector<int>& arr, int key) {
        return helper(0, arr.size()-1, arr, key);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends