//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    typedef long long ll;
    pair<ll, ll> getLow_High(vector<int> &arr){
        ll low = 0, high = 0;
        for(int &x: arr){
            low = max(low, (ll) x);
            high += x;
        }
        return {low, high};
    }
    int reqStudents(vector<int> &arr, int n, ll maxPages){
        int stud = 1, pages = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] + pages > maxPages){
                pages = arr[i];
                stud++;
            }
            else {
                pages += arr[i];
            }
        }
        return stud;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) 
            return -1;
        pair<ll, ll> it = getLow_High(arr);
        ll low = it.first, high = it.second;
        while(low <= high){
            ll mid = low+(high-low)/2;
            if(reqStudents(arr, n, mid) > k){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends