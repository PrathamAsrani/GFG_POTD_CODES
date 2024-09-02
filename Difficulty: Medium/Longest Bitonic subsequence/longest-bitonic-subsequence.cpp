//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &arr) {
        // code here
        vector<int> LIS(n, 1), LDS(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j] && LIS[j]+1 > LIS[i]){
                    LIS[i] = LIS[j]+1;
                }
            }
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = n-1; j > i; j--){
                if(arr[i] > arr[j] && LDS[j]+1 > LDS[i]){
                    LDS[i] = LDS[j]+1;
                }
            }
        }
        int ans = 1;
        for(int i = 0; i < n; i++){
            if(LIS[i] != 1 && LDS[i] != 1)
                ans = max(ans, LIS[i] + LDS[i]);
        }
        return ans-1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends