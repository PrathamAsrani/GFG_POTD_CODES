//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        /*
        vector<int> ans;
        for(int &x: arr){
            int ele = A*(x*x) + B*x + C;
            ans.push_back(ele);
        }
        sort(ans.begin(), ans.end());
        return ans;
        */
        
        auto eval = [&](int ele) {
            return A*(ele*ele) + B*ele + C;
        };
        
        int n = arr.size();
        vector<int> ans(n);
        int left = 0, right = n-1;
        int index = (A >= 0) ? n-1 : 0; 
        // if(A >= 0) then start filling ans from back else from front
        while(left <= right){
            int leftVal = eval(arr[left]);
            int rightVal = eval(arr[right]);
            
            if(A >= 0){
                if(leftVal > rightVal){
                    ans[index--] = leftVal;
                    left++;
                }
                else{
                    ans[index--] = rightVal;
                    right--;
                }
            }
            else {
                if(leftVal < rightVal){
                    ans[index++] = leftVal;
                    left++;
                }
                else{
                    ans[index++] = rightVal;
                    right--;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends