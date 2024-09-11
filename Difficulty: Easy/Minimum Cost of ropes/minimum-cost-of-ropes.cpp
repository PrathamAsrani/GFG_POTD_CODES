//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    typedef long long ll;
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        multiset<ll> ms;
        for(ll &x: arr) ms.insert(x);
        ll ans = 0;
        while(ms.size() > 1){
            ll tp1 = *ms.begin();
            ms.erase(ms.begin());
            ll tp2 = *ms.begin();
            ms.erase(ms.begin());
            ans += tp1 + tp2;
            ms.insert(tp1+tp2);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends