//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &arr) {
        int i = 0, t = n, p = 0;
        while(i < t){
            int pro = 0, _p = 0;
            for(i; i < n; i++){
                if(arr[i] < arr[i+1]) {
                    _p = arr[i];
                    break;
                }
            }
            i++;
            for(i; i < n; i++){
                if(arr[i] > _p){
                    int temp = arr[i] - _p;
                    pro = max(pro, temp);
                    p += pro;
                    break;
                }
            }
        }
        return p;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends