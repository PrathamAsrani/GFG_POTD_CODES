//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

vector<long long int> findLow_High(vector<int>& a, int n){
        long long int low = a[0], high = a[0];
        for(int i = 1; i < n; i++){
            high += a[i];
            if(low < a[i]) low = a[i];
        }
        return {low, high};
    }

int cntRequiredPainters(vector<int> &boards, int n, long long int paintArea){
    int cntPainter = 1, area = boards[0];
    for(int i = 1; i < n; i++){
        if((area + boards[i]) <= paintArea) area += boards[i];
        else {
            cntPainter++;
            area = boards[i];
        }
    }
    return cntPainter;
}

class Solution {
  public:
    int splitArray(int arr[] ,int n, int k) {
        vector<int> boards(n);
        for(int i = 0; i < n ; i++)
            boards[i] = arr[i];
        vector<long long int> i = findLow_High(boards, n);
        long long int low = i[0], high = i[1];
        while(low <= high){
            long long int mid = low + (high-low)/2;
            if(cntRequiredPainters(boards, n, mid) <= k) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends