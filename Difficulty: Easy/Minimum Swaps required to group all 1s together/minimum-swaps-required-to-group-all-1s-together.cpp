//{ Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n);

// Driver Code
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << minSwaps(a, n) << endl;
    }

    return 0;
}

// } Driver Code Ends


int minSwaps(int arr[], int n) {
    int ans = n, wnd = 0, one = 0;
    for(int i = 0; i < n; i++) wnd += arr[i];
    for(int i = 0, j = 0; j < n; j++){
        one += arr[j];
        if(j-i+1 == wnd){
            ans = min(ans, wnd-one);
            one -= arr[i++];
        }
    }
    return ans == n ? -1 : ans;
}