class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int curr_i,int curr_j,vector<vector<char>>& board,vector<vector<int>> &vis,int n,int m){
        vis[curr_i][curr_j]=1;
        for(int i=0;i<4;i++){
            int next_i=curr_i+dir[i][0];
            int next_j=curr_j+dir[i][1];
            if(next_i>=0 && next_i<n && next_j>=0 && next_j<m && board[next_i][next_j]=='X' && !vis[next_i][next_j]){
                dfs(next_i,next_j,board,vis,n,m);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    dfs(i,j,board,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt++;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna