//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void heapify(vector<int> &arr, int n, int i){
        int large = i, left = 2*i+1, right = 2*i+2;
        if(left < n && arr[left] > arr[large])
            large = left;
        if(right < n && arr[right] > arr[large])
            large = right;
        if(large != i){
            swap(arr[i], arr[large]);
            heapify(arr, n, large);
        }
    }
    void heap_sort(vector<int> &arr){
        int n = arr.size();
        for(int i = n/2-1; i >= 0; i--)
            heapify(arr, n, i);
        for(int i = n-1; i > 0; i--){
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // Your Code goes here.
        heap_sort(greed);
        heap_sort(cookie);
        int j = 0;
        for(int i = 0; i < cookie.size(); i++){
            if(cookie[i] >= greed[j])
                j++;
            if(j == greed.size())
                break;
        }
        return j;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> greed;
        int num;
        while (ss >> num)
            greed.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> cookie;
        ss.str(input);
        while (ss >> num)
            cookie.push_back(num);

        Solution obj;
        cout << obj.maxChildren(greed, cookie) << endl;
    }
    return 0;
}
// } Driver Code Ends