class Solution {
public:
    vector<vector<int>> dir = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2},
                               {2, -1}, {2, 1},   {1, -2}, {1, 2}};
    bool f(int y,int x,int cnt,vector<vector<int>>& grid,int n){
        if(cnt==n*n-1) return true;
        for(int i=0;i<8;i++){
            int new_i=y+dir[i][0];
            int new_j=x+dir[i][1];
            if(new_i>=0 && new_j>=0 && new_i<n && new_j<n && grid[new_i][new_j]==cnt+1){
                if(f(new_i,new_j,cnt+1,grid,n)) return true;
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0)
        return false;

    return f(0, 0, 0, grid, n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna