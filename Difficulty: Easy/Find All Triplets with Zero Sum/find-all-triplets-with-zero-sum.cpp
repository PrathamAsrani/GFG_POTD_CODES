//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        /*
        vector<pair<int, int>> v;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.first < b.first;
        });
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = i+1, k = n-1; j < k; ){
                if(v[i].first + v[j].first + v[k].first == 0){
                    ans.push_back({v[i].second, v[j].second, v[k].second});
                }
                if(v[i].first + v[j].first + v[k].first > 0){
                    k--;
                }else if(v[i].first + v[j].first + v[k].first < 0){
                    j++;
                }
            }
        }
        for(auto &vec: ans){
            sort(vec.begin(), vec.end());
        }
        return ans;
        */
        
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> umpp;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(umpp.find(arr[i]+arr[j]) != umpp.end() && i != j && j != umpp[arr[i]+arr[j]] && i != umpp[arr[i]+arr[j]]){
                    ans.push_back({i, j, umpp[arr[i]+arr[j]]});
                    // cout << i << " " << j << " " << umpp[arr[i]+arr[j]] << "\n";
                }
                umpp[-arr[j]] = j;
            }
        }
        for(auto &vec: ans){
            sort(vec.begin(), vec.end());
        }
        set<vector<int>> uniqueSet(ans.begin(), ans.end());
        return vector<vector<int>>(uniqueSet.begin(), uniqueSet.end());
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends