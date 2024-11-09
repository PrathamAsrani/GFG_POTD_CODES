//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

int fast = []{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());  // O(n log n) sorting
        int n = arr.size();
        if (n == 0) return "0";
        if (n == 1) return to_string(arr[0]);

        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) a.push_back(arr[i]);
            else b.push_back(arr[i]);
        }

        // Sum the two 'numbers' stored in vectors `a` and `b`
        string ans;
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        ostringstream oss;

        // Build the answer in reverse order to avoid direct string concatenation
        while (i >= 0 || j >= 0 || carry) {
            int digitA = i >= 0 ? a[i--] : 0;
            int digitB = j >= 0 ? b[j--] : 0;
            int sum = digitA + digitB + carry;
            oss << (sum % 10);  // Append the current digit
            carry = sum / 10;
        }

        // Convert ostringstream to a string and reverse it for final result
        string result = oss.str();
        reverse(result.begin(), result.end());

        // Remove any leading zeros
        size_t startIdx = result.find_first_not_of('0');
        return startIdx == string::npos ? "0" : result.substr(startIdx);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends