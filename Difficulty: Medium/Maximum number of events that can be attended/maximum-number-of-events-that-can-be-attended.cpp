//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class ds{
    public:
        int s, e;
        ds(int x = 0, int y = 0) : s(x), e(y) {};
};

class Solution {
  public:
    int maxEvents(int start[], int end[], int n) {
        // code here
        ds arr[n];
        for(int i = 0; i < n; i++)
            arr[i] = ds(start[i], end[i]);
        sort(arr, arr+n, [&](ds &a, ds &b){
            return a.s < b.s;
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, ans = 0, day = 0;
        while(!pq.empty() || i < n){
            if(pq.empty()) day = arr[i].s;
            while(i < n && arr[i].s <= day)
                pq.push(arr[i++].e);
            pq.pop();
            ans++;
            day++;
            while(!pq.empty() && day > pq.top())
                pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}
// } Driver Code Ends