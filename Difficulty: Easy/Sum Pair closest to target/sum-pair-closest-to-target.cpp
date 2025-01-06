//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        int a = -1, b = -1, diff = 1e9;
        for(int i = 0, j = arr.size()-1; i < j; ){
            int sum = arr[i] + arr[j], d = abs(target - sum);
            if(d < diff){
                diff = d;
                a = arr[i];
                b = arr[j];
            }
            
            if(sum < target)
                i++;
            else if(sum > target)
                j--;
            else {
                return {arr[i], arr[j]};
            }
        }
        if(a == -1)
            return {};
        return {a, b};
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends