class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        vector<vector<int>> res, ans;
        int n = occupiedIntervals.size();
        for (int i = 0; i < n; i++) {
            int s = occupiedIntervals[i][0], f = occupiedIntervals[i][1];
            if (s >= freeStart && f <= freeEnd)
                continue;
            if (s < freeStart && f >= freeStart && f <= freeEnd) {
                res.push_back({s, freeStart - 1});
                continue;
            }
            if (s < freeStart && f > freeEnd) {
                res.push_back({s, freeStart-1});
                res.push_back({freeEnd+1, f});
                continue;
            }
            if (s <= freeEnd && s >= freeStart && f > freeEnd) {
                res.push_back({freeEnd + 1, f});
                continue;
            }
            res.push_back({s, f});
        }
        sort(res.begin(), res.end());
        int m = res.size();
        for (int i = 0; i < m;i++) {
            int s = res[i][0];
            int f = res[i][1];
            int ulf = f;

            while (i + 1 < m && res[i + 1][0] <= 1 + ulf) {
                ulf = max(ulf, res[i + 1][1]);
                i++;
            }

            ans.push_back({s, ulf});
            // i++;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna