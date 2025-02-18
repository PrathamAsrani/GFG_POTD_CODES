//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    typedef pair<int, pair<int, int>> ppi;
    int calculateDis(int x1, int y1, int x2, int y2){
        return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    }
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        vector<vector<int>> ans;
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        for(vector<int> &point: points){
            pq.push({calculateDis(0, 0, point[0], point[1]), {point[0], point[1]}});
        }
        while(!pq.empty() && k-- > 0){
            ppi top = pq.top();
            pq.pop();
            ans.push_back({top.second.first, top.second.second});
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends