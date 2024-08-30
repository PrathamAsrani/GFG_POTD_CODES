//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int>> ans;
    void getBoard(vector<vector<int>> &board, int n){
        vector<int> tmp;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(board[i][j]) tmp.push_back(j+1);
        ans.push_back(tmp);
    }
    bool isSafe(vector<vector<int>> &board, int row, int col){
        int n = board.size();
        // check row
        for(int i = 0; i < n; i++) if(board[row][i] == 1) return false;
        // check col
        for(int i = 0; i < n; i++) if(board[i][col] == 1) return false;
        
        // check diag left-up
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) if(board[i][j] == 1) return false;
        // check diag left-down
        for(int i = row, j = col; i < n && j < n; i++, j++) if(board[i][j] == 1) return false;
        
        // check diag right-up
        for(int i = row, j = col; i < n && j >= 0; i++, j--) if(board[i][j] == 1) return false;
        // check diag right-down
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) if(board[i][j] == 1) return false;
        
        return true;
    }
    void solve(int col, int n, vector<vector<int>> &board){
        if(col == n) {
            getBoard(board, n);
            return ;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(board, row, col)){
                board[row][col] = 1;
                solve(col+1, n, board);
                board[row][col] = 0;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(0, n, board);
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