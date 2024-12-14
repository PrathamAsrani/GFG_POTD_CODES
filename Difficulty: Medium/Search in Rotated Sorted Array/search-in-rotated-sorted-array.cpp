//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int find(vector<int> &arr, int l, int r, int &key){
        if(l > r) return -1;
        int mid = l+(r-l)/2;
        if(arr[mid] == key){
            return mid;
        }
        int left = find(arr, l, mid-1, key);
        if(left != -1){
            return left;
        }
        int right = find(arr, mid+1, r, key);
        if(right != -1){
            return right;
        }
        return -1;
    }
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        return find(arr, 0, arr.size()-1, key);
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
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends