class Solution {
public:
vector<vector<int>> dir={{-1,-1},{0,-1},{1,-1}};
bool check(vector<string> &board,int x,int y,int n){
    for(auto &d:dir){
         int new_i=y, new_j=x;
        while(true){
        new_i+=d[0];
        new_j+=d[1];
        if(new_i<0 || new_j<0 || new_j>=n || new_i>=n) break;
        if(board[new_i][new_j]=='Q') return false;
        }
    }
    return true;
}
    void solve(int ind, vector<string>& board, vector<vector<string>>& ans,
               int n) {
        if (ind == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(board, ind, i,n)) {
                board[i][ind] = 'Q';
                solve(ind+1,board,ans,n);
                board[i][ind]='.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna