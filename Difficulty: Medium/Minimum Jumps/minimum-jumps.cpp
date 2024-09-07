//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int jump = 0, n = arr.size(), reach = 0, mx_reach = 0;
        for(int i = 0; i < n; i++){
            if(reach >= n-1) return jump;
            mx_reach = max(mx_reach, i+arr[i]);
            if(reach == i){
                if(mx_reach <= i) return -1;
                jump++;
                reach = mx_reach;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends