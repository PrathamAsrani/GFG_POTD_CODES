//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
    vector<int> ans;
    
    void merge(vector<pair<int, int>> &v, int l, int m, int r) {
        int sz = r-l+1;
        vector<pair<int, int>> tmp(sz, {0, 0});
        int i = l, j = m+1, k = 0;
        
        while(i <= m && j <= r) {
            if(v[i].first <= v[j].first) {
                tmp[k++] = v[j++];
            } else {
                ans[v[i].second] += (r-j+1);
                tmp[k++] = v[i++];
            }
        }
        
        while(i <= m) tmp[k++] = v[i++];
        while(j <= r) tmp[k++] = v[j++];
        
        for(int it = 0; it < sz; it++)
            v[it+l] = tmp[it];
    }
    
    void ms(vector<pair<int, int>> &v, int l, int r){
        if(l < r) {
            int m = (l+r)/2;
            ms(v, l, m);
            ms(v, m+1, r);
            merge(v, l, m, r);
        }
    }
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        int n = arr.size();
        /*
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i+1; j < n; j++){
                if(arr[i] > arr[j])
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
        */
        
        vector<pair<int, int>> v;
        for(int i = 0; i < n; v.push_back({arr[i], i}), i++);
        ans.resize(n, 0);
        ms(v, 0, n-1);
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
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends