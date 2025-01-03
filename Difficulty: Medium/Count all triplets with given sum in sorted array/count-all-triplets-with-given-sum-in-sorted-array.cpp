//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size(), ans = 0;
        /*
        for(int i = 0; i < n; i++){
            unordered_map<int, int> mp;
            for(int j = i+1; j < n; j++){
                ans += mp[arr[i] + arr[j]];
                mp[target - arr[j]]++;
            }
        }
        return ans;
        */
        
        for(int i = 0; i < n; i++){
            for(int low = i+1, high = n-1; low < high; ){
                int sum = arr[i] + arr[low] + arr[high];
                if(sum > target){
                    high--;
                }
                else if(sum < target){
                    low++;
                }
                else {
                    int ele1 = arr[low], ele2 = arr[high];
                    int cnt1 = 0, cnt2 = 0;
                    while(low <= high && arr[low] == ele1){
                        low++; cnt1++;
                    }
                    while(low <= high && arr[high] == ele2){
                        high--; cnt2++;
                    }
                    if(ele1 == ele2)
                        ans += (cnt1 * (cnt1-1))/2;
                    else ans += cnt1*cnt2;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends