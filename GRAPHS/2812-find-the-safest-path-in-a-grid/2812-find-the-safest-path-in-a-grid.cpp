#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool dfs(int mid, vector<vector<int>>& safe_score,
             vector<vector<int>>& grid, vector<vector<int>>& vis, int y,
             int x) {
        if (y == grid.size() - 1 && x == grid[0].size() - 1)
            return true;

        vis[y][x] = 1;

        for (int i = 0; i < 4; i++) {
            int new_i = y + dir[i][0];
            int new_j = x + dir[i][1];

            // 1. Check bounds FIRST to prevent memory overflow (vis[-1] crash)
            // 2. Check unvisited cell
            // 3. Check safeness requirement (>= mid)
            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 &&
                new_j < grid[0].size() && vis[new_i][new_j] == -1 &&
                safe_score[new_i][new_j] >= mid) {

                // Propagate true up the call stack if a path is found
                if (dfs(mid, safe_score, grid, vis, new_i, new_j))
                    return true;
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> safe_score(n, vector<int>(m, -1));

        // Step 1: Your exact loop to gather thief coordinates
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1){
                    q.push({i, j});
                    safe_score[i][j] = 0;}
            }
        }

        // Step 2: multi-src bfs from thief cells
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_i = y + dir[i][0];
                int new_j = x + dir[i][1];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
                    safe_score[new_i][new_j] == -1) {
                    safe_score[new_i][new_j] = safe_score[y][x] +1;
                    q.push({new_i, new_j});
                }
            }
        }

        // Step 3: Binary Search on Safeness Factor
        int l = 0, r = 800;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Reset visited matrix inside the loop for every binary search test
            vector<vector<int>> vis(n, vector<int>(m, -1));

            // Check start and end cells against mid requirement (>= mid)
            if (safe_score[0][0] >= mid && safe_score[n - 1][m - 1] >= mid &&
                dfs(mid, safe_score, grid, vis, 0, 0)) {
                ans = mid; // Path exists, try for a higher safeness factor
                l = mid + 1;
            } else {
                r = mid - 1; // Score too high, reduce target
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna