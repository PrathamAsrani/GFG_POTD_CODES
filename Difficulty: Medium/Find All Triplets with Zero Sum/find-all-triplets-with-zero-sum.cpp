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
        vector<vector<int>> ans;
        vector<pair<int, int>> v;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end(), [](auto &x, auto &y){
            return x.first < y.first;
        });
        for(int i = 0; i < n; i++){
            for(int j = i+1, k = n-1; j < k; ){
                if(v[i].first + v[j].first + v[k].first == 0){
                    ans.push_back({v[i].second, v[j].second, v[k].second});
                }
                
                if(v[i].first + v[j].first + v[k].first < 0) j++;
                else k--;
            }
        }
        for(auto &vec: ans){
            sort(vec.begin(), vec.end());
        }
        return ans;
        */
        
        int n = arr.size();
        set<vector<int>> ans;
        // a+b+c = 0. Therefore, a+b = -c, we will hash -c and it's index
        for(int i = 0; i < n; i++){
            unordered_map<int, int> mp;
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                if(mp.find(arr[i] + arr[j]) != mp.end() && i != mp[arr[i] + arr[j]] && j != mp[arr[i] + arr[j]]){
                    vector<int> tup = {i, j, mp[arr[i] + arr[j]]};
                    sort(tup.begin(), tup.end());
                    ans.insert(tup);
                }
                
                mp[-arr[j]] = j; // hashing c
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
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