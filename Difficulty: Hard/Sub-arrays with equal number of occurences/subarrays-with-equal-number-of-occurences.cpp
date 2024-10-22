//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        /*
        int n = arr.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            int xx = 0, yy = 0;
            for(int j = i; j < n; j++){
                if(arr[j] == x) xx++;
                else if(arr[j] == y) yy++;
                
                if(xx == yy) cnt++;
            }
        }
        return cnt;
        */
        
        unordered_map<int, int> umpp;
        int n = arr.size();
        int cntX[n], cntY[n];
        for(int i = 0; i < n; i++){
            if(arr[i] == x){
                if(i == 0) cntX[i] = 1;
                else cntX[i] = cntX[i-1]+1;
            } else {
                if(i == 0) cntX[i] = 0;
                else cntX[i] = cntX[i-1];
            }
            
            if(arr[i] == y){
                if(i == 0) cntY[i] = 1;
                else cntY[i] = cntY[i-1]+1;
            } else {
                if(i == 0) cntY[i] = 0;
                else cntY[i] = cntY[i-1];
            }
            
            umpp[cntX[i] - cntY[i]]++;
        }
        
        int cnt = umpp[0];
        for(auto it = umpp.begin(); it != umpp.end(); it++){
            cnt += ((it->second) * (it->second - 1))/2;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends