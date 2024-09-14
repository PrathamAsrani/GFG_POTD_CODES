//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxProductSubarrayOfSizeK(vector<int>& arr, int k) {
        // Your code goes here
        sort(arr.begin(), arr.end());
    
    int n = arr.size();
    long long maxProduct = 1;
    
    // Case 1: Multiply the largest k elements directly (likely the best case)
    long long positiveProduct = 1;
    for (int i = n - 1; i >= n - k; --i) {
        positiveProduct *= arr[i];
    }

    maxProduct = positiveProduct;

    // Case 2: Consider mixing negative numbers for better results (if applicable)
    int left = 0, right = n - 1;
    long long currentProduct = 1;
    int count = 0;

    while (count < k) {
        // Decide whether to take from the start (negative) or end (positive)
        if (abs(arr[left]) > abs(arr[right])) {
            currentProduct *= arr[left++];
        } else {
            currentProduct *= arr[right--];
        }
        count++;
    }
    
    maxProduct = max(maxProduct, currentProduct);
    return maxProduct;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline character after k

        Solution ob;
        cout << ob.maxProductSubarrayOfSizeK(arr, k) << "\n";
    }
    return 0;
}

// } Driver Code Ends