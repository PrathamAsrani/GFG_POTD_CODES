//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  long long merge(vector<int> &arr, int l, int m, int r){
      long long cnt = 0;
      vector<int> tmp(r - l + 1);
      int i = l, j = m+1, k = 0;
      while(i <= m && j <= r){
          if(arr[i] <= arr[j]){
              tmp[k++] = arr[i++];
          }
          else {
              cnt += (m-i+1);
              tmp[k++] = arr[j++];
          }
      }
      while(i <= m){
          tmp[k++] = arr[i++];
      }
      while(j <= r){
          tmp[k++] = arr[j++];
      }
      for(int it = 0; it < r-l+1; it++){
          arr[l+it] = tmp[it];
      }
      return cnt;
  }
  long long mergeSort(vector<int> &arr, int l, int r){
      long long cnt = 0;
      if(l < r){
          int m = l+(r-l)/2;
          cnt += mergeSort(arr, l, m);
          cnt += mergeSort(arr, m+1, r);
          cnt += merge(arr, l, m, r);
      }
      return cnt;
  }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return mergeSort(arr, 0, arr.size()-1);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends