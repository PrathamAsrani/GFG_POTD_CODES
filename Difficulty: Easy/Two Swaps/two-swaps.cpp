//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        vector<int> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());
        int n = arr.size();
        
        function<int()> getCount = [&]() {
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(arr[i] != sorted[i]){
                    cnt++;
                }
            }
            return cnt;
        };
        
        function<void()> fun = [&]() {
            for(int i = 0; i < n; i++){
                if(arr[i] != sorted[i]){
                    int idx = arr[i];
                    arr[i] = arr[idx-1];
                    arr[idx-1] = idx;
                    break;
                }
            }
        };
        
        fun();
        fun();
        return getCount() == 0;
    }
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends