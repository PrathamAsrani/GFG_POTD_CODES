//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
typedef long long ll;
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        ll ans = -1e9, sum = 0;
        for(int x: arr){
            sum += x;
            if(ans < sum)
                ans = sum;
            if(sum < 0) 
                sum = 0;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends