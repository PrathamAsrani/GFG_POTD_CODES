//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void s(int *a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void segregate0and1(vector<int> &arr) {
        int l = 0, n = arr.size();
        // for(int i = 0; i < n; i++){
        //     if(arr[i] < arr[l]){
        //         s(&arr[l], &arr[i]);
        //     } else l = i;
        // }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) if(arr[i]) cnt++;
        while(cnt--){
            arr[--n] = 1;
        }
        while(n){
            arr[--n] = 0;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends