//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int jump = 0, mx_reach = 0, reach = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            if(reach >= n-1)
                return jump;
            mx_reach = max(mx_reach, i + arr[i]);
            if(reach == i){
                if(i > mx_reach)
                    return -1;
                reach = mx_reach; 
                jump++;
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
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends