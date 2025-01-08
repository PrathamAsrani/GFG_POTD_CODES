//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        long long ans = 0;
        int n = arr.size();
        if(n <= 2)
            return 0;
        /*
        // tc: O(N^3), sc: O(1)
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(arr[i] + arr[j] > arr[k] 
                        && arr[i] + arr[k] > arr[j]
                        && arr[j] + arr[k] > arr[i])
                        ans++;
                }
            }
        }
        return ans;
        */
        
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int sum = arr[i] + arr[j];
                int idx = lower_bound(arr.begin() + j + 1, arr.end(), sum) - arr.begin();
                ans += idx - j - 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends