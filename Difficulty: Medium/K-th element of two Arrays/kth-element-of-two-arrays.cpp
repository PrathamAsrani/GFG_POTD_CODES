//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& a, vector<int>& b) {
        // brute force 
        // TC: O(min(k, max(n, m)))
        int n = a.size(), m = b.size(), i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] <= b[j]){
                k--;
                if(k == 0) return a[i];
                i++;
            } else {
                k--;
                if(k == 0) return b[j];
                j++;
            }
        }
        while(i < n){
            k--;
            if(k == 0) return a[i];
            i++;
        }
        while(j < m){
            k--;
            if(k == 0) return b[j];
            j++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends