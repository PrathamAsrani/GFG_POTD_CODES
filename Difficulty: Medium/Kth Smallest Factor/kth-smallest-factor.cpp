//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<int> findFactors(int num){
        vector<int> fact;
        for(int i = 1; i <= num; i++){
            if(num%i == 0){
                fact.push_back(i);
            }
        }
        return fact;
    }
    vector<int> helper(int num){
        vector<int> v1, v2;
        int sqr = sqrt(num);
        for(int i = 1; i <= sqr; i++){
            if(num%i == 0){
                v1.push_back(i);
                v2.push_back(num/i);
            }
        }
        reverse(v2.begin(), v2.end());
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
  public:
    int kThSmallestFactor(int n, int k) {
        /*
        vector<int> fact = findFactors(n);
        if(fact.size() >= k) return fact[k-1];
        return -1;
        */
        
        vector<int> fact = helper(n);
        fact.erase(unique(fact.begin(), fact.end()), fact.end());
        if(fact.size() >= k) return fact[k-1];
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;

        cin >> N >> K;

        Solution ob;
        cout << ob.kThSmallestFactor(N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends