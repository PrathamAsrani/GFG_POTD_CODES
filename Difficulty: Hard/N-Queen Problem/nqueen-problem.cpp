//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void addSolution(int n, vector<vector<int>> &board, vector<vector<int>> &ans){
        vector<int> temp;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(board[i][j] == 1) temp.push_back(j+1);
        ans.push_back(temp);
    }
    bool isSafe(int row, int col, int n, vector<vector<int>> &board){
        for(int i = 0; i < n; i++) if(board[i][col] == 1) return false; // check row
        for(int i = 0; i < n; i++) if(board[row][i] == 1) return false; // check col
        int x = row, y = col;
        while(x >= 0 && y >= 0){
            if(board[x--][y--] == 1) return false; // check diagonal left up
        }
        x = row, y = col;
        while(x < n && y < n){
            if(board[x++][y++] == 1) return false; // check diagonal right down
        }
        x = row, y = col;
        while(x >= 0 && y < n){
            if(board[x--][y++] == 1) return false; // check diagonal left down
        }
        x = row, y = col;
        while(x < n && y >= 0){
            if(board[x++][y--] == 1) return false; // check diagonal right up
        }
        return true;
    }
    void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans){
        if(col == n){
            addSolution(n, board, ans);
            return ;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(row, col, n, board) == true){
                board[row][col] = 1;
                solve(col+1, n, board, ans);
                board[row][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans, board(n, vector<int>(n, 0));
        solve(0, n, board, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends