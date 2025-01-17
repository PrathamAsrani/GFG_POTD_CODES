//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        vector<int> ans;
        int cnt_0 = 0, prod = 1;
        for(int &num: arr){
            if(num == 0)
                cnt_0++;
            else 
                prod *= num;
        }
        if(cnt_0 >= 2){
            return vector<int>(arr.size(), 0);
        }
        else if(cnt_0 == 0){
            for(int i = 0; i < arr.size(); i++){
                ans.push_back(prod/arr[i]);
            }
        }
        else {
            ans = vector<int>(arr.size(), 0);
            for(int i = 0; i < arr.size(); i++){
                if(arr[i] == 0){
                    ans[i] = prod;
                    break;
                }
            }
        }
        return ans;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends