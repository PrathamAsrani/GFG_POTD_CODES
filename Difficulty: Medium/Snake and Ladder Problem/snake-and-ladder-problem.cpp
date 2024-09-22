//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        int moves[31];
        bool vis[31];
        for(int i = 0; i <= 30; i++){
            vis[i] = false;
            moves[i] = -1;
        }
        
        for(int i = 0; i < 2*N; i += 2){
            moves[arr[i]] = arr[i+1]; // it can be snake or ladder
        }
        
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;
        
        while(!q.empty()){
            int cell = q.front().first, dis = q.front().second;
            q.pop();
            if(cell == 30) 
                return dis;
            for(int i = cell+1; i <= cell+6 && i <= 30; i++){
                if(!vis[i]){
                    vis[i] = true;
                    if(moves[i] != -1){
                        q.push({moves[i], dis+1});
                    } else {
                        q.push({i, dis+1});
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends