class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }

                if(grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        // No fresh oranges
        if(cnt == 0) return 0;

        int moves = 0;

        while(!q.empty() && cnt > 0) {

            int sz = q.size();

            while(sz--) {

                auto [y, x] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {

                    int new_y = y + dir[i][0];
                    int new_x = x + dir[i][1];

                    // Valid cell, unvisited, and fresh
                    if(new_y >= 0 && new_y < n &&
                       new_x >= 0 && new_x < m &&
                       vis[new_y][new_x] == -1 &&
                       grid[new_y][new_x] == 1) {

                        vis[new_y][new_x] = 1;
                        grid[new_y][new_x] = 2;

                        cnt--;              
                        q.push({new_y, new_x});
                    }
                }
            }

            moves++;
        }

        if(cnt > 0) return -1;

        return moves;
    }
};