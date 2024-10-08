//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 100000;
        vector<int> dis(mod, 1e5);
        dis[start] = 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        while(!q.empty()){
            int node = q.front().first, steps = q.front().second;
            q.pop();
            if(node == end)
                return steps;
            for(int &x: arr){
                int num = (x*node)%mod;
                if(dis[num] > steps+1){
                    dis[num] = steps + 1;
                    q.push({num, dis[num]});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends