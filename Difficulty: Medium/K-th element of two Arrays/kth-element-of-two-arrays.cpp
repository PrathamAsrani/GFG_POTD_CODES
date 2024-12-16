//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int fun(vector<int> &a, vector<int> &b, int l1, int r1, int l2, int r2, int k){
        if(l1 > r1) return b[l2+k];
        if(l2 > r2) return a[l1+k];
        
        int m1 = (r1-l1)/2;
        int m2 = (r2-l2)/2;
        
        if(m1+m2 < k){
            if(a[l1+m1] > b[l2+m2])
                return fun(a, b, l1, r1, l2+m2+1, r2, k-m2-1);
            else 
                return fun(a, b, l1+m1+1, r1, l2, r2, k-m1-1);
        }
        else {
            if(a[l1+m1] > b[l2+m2])
                return fun(a, b, l1, l1+m1-1, l2, r2, k);
            else 
                return fun(a, b, l1, r1, l2, l2+m2-1, k);
        }
    }
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        return fun(a, b, 0, a.size()-1, 0, b.size()-1, k-1);
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
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends