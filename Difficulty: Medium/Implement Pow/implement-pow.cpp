//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        /*
        double ans = 1;
        for(int i = 0; i < abs(e); i++){
            ans = ans*b;
        }
        if(e < 0){
            ans = 1/ans;
        }
        return ans;
        */
        
        if (e == 0)
        return 1;
  
        if (e < 0)
            return 1 / power(b, -e);
          
        double temp = power(b, e / 2);
        
        if (e % 2 == 0)
            return temp * temp;
        else
            return b * temp * temp;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends