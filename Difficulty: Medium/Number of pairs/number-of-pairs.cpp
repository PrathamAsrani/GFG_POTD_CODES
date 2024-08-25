//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef long long ll;

class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        /*
        ll ans = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < brr.size(); j++){
                if(brr[j] * log(arr[i]) > arr[i] * log(brr[j])){
                    ans++;
                }
            }
        }
        return ans;
        */
        
        ll ans = 0;
        int one = 0, two = 0, three_four = 0;
        for(int x: brr){
            if(x == 1) one++;
            if(x == 2) two++;
            if(x == 3 or x == 4) three_four++;
        }
        sort(brr.begin(), brr.end());
        
        for(int x: arr){
            if(x == 1) continue;
            ans += one;
            if(x == 2) ans -= three_four;
            if(x == 3) ans += two;
            
            int idx = -1, low = 0, high = brr.size()-1;
            while(low <= high){
                int mid = (low+high)/2;
                if(brr[mid] <= x){
                    idx = mid;
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            
            ans += (brr.size()-idx-1);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends