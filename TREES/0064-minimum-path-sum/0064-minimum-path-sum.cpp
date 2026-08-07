class Solution {
public:
vector<vector<int>> dp;
    int f(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i>n-1 || i<0 || j>m-1 || j<0) return 1e9;
     if(i==n-1 && j==m-1) return grid[n-1][m-1];
     if(dp[i][j]!=-1)return dp[i][j];
     int down = grid[i][j]+f(i+1,j,n,m,grid);
     int right=grid[i][j]+f(i,j+1,n,m,grid);
     return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
dp.assign(n, vector<int>(m, -1));
        // dp.assign()
        return f(0,0,n,m,grid);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna