//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& cit) {
        // code here
        int l = 0, h = cit.size(), ans = 0;
        while(l <= h){
            int mid = (l+h)/2;
            bool check = [&]{
                int cnt = 0;
                for(int i = 0; i < cit.size(); i++){
                    if(cit[i] >= mid){
                        cnt++;
                        if(cnt >= mid)
                            return 1;
                    }
                }
                return 0;
            }();
            if(check){
                ans = mid;
                l = mid+1;
            }
            else h = mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends