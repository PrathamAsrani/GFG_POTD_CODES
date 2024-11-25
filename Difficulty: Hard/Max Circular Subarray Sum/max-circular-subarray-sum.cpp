//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        if(n <= 0){
            return 0;
        }
        int maxi = arr[0], mini = arr[0], curr_maxi = 0, curr_mini = 0, sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            curr_maxi = max(arr[i], arr[i] + curr_maxi);
            maxi = max(maxi, curr_maxi);
            
            curr_mini = min(arr[i], arr[i] + curr_mini);
            mini = min(mini, curr_mini);
        }
        if(maxi > 0)
            return max(maxi, sum - mini);
        else return maxi;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends