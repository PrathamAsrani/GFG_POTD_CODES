//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        /*
        vector<double> medians;
        multiset<int> ms;
        for(int &num: arr){
            ms.insert(num);
            auto it = next(ms.begin(), ms.size()/2);
            if(ms.size()&1){
                medians.push_back(*it);
            }
            else {
                auto _it = prev(it);
                medians.push_back((*it + *_it)/2.0);
            }
        }
        return medians;
        */
        
        priority_queue<double> maxHeap;
        priority_queue<double, vector<double>, greater<double>> minHeap;
        vector<double> medians;
        for(int &num: arr){
            if(maxHeap.empty() || num <= maxHeap.top()) maxHeap.push(num);
            else minHeap.push(num);
            
            if(maxHeap.size() > minHeap.size()+1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if(minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            if(maxHeap.size() > minHeap.size()){
                medians.push_back(maxHeap.top());
            }else{
                medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            }
        }
        return medians;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends