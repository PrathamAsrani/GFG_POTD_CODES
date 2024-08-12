//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
    int helper(vector<int> &a, vector<int> &b, int l1, int r1, int l2, int r2, int k){
        if(l1 > r1) return b[l2+k];
        if(l2 > r2) return a[l1+k];
        
        int m1 = (r1-l1)/2;
        int m2 = (r2-l2)/2;
        
        if(m1 + m2 < k){
            if(a[l1+m1] > b[l2+m2]){
                return helper(a, b, l1, r1, l2+m2+1, r2, k-m2-1);
            } else {
                return helper(a, b, l1+m1+1, r1, l2, r2, k-m1-1);
            }
        } else {
            if(a[l1+m1] > b[l2+m2]){
                return helper(a, b, l1, l1+m1-1, l2, r2, k);
            } else {
                return helper(a, b, l1, r1, l2, l2+m2-1, k);
            }
        }
    }
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size() + arr2.size();
        if(n&1){
            return helper(arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1, n/2-1);
        } else {
            int a = helper(arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1, n/2-1);
            int b = helper(arr1, arr2, 0, arr1.size()-1, 0, arr2.size()-1, n/2);
            return a+b;
        }
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends