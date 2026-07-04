class Solution {
public:
    int minOperations(string s1, string s2) {
        auto melorvanti = make_pair(s1, s2);

        int n = s1.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(2, INF));
        dp[n][0] = dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int removed = 0; removed <= 1; removed++) {
                int cur = removed ? 0 : (s1[i] - '0');

                // Don't use the (i, i+1) operation.
                int cost = 0;
                int bit = cur;
                if (bit == 0 && s2[i] == '1') {
                    cost++;
                    bit = 1;
                }
                if (bit == (s2[i] - '0')) {
                    dp[i][removed] = min(dp[i][removed], cost + dp[i + 1][0]);
                }

                // Use the (i, i+1) operation.
                if (i + 1 < n) {
                    int c = 1; // remove pair
                    if (cur == 0) c++;          // create current 1
                    if (s1[i + 1] == '0') c++; // create next 1

                    if (s2[i] == '0') {
                        dp[i][removed] = min(dp[i][removed], c + dp[i + 1][1]);
                    } else {
                        // recreate current after removing it
                        dp[i][removed] = min(dp[i][removed], c + 1 + dp[i + 1][1]);
                    }
                }
            }
        }

        return dp[0][0] >= INF ? -1 : dp[0][0];
    }
};