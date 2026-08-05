class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        deque<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        int start = health - grid[0][0];
        if(start <= 0) return false;

        dist[0][0] = start;
        q.push_front({start, {0,0}});

        while(!q.empty()) {
            auto [curr, p] = q.front();
            q.pop_front();

            auto [y, x] = p;

            for(auto &d : dir) {
                int ny = y + d[0];
                int nx = x + d[1];

                if(ny < 0 || nx < 0 || ny >= n || nx >= m)
                    continue;

                int nxt = curr - grid[ny][nx];

                if(nxt > dist[ny][nx]) {
                    dist[ny][nx] = nxt;

                    if(grid[ny][nx] == 0)
                        q.push_front({nxt, {ny, nx}});
                    else
                        q.push_back({nxt, {ny, nx}});
                }
            }
        }

        return dist[n-1][m-1] >= 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna