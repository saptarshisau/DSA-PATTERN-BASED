class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        ll res = 0LL;
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));
        vector<ll> sum_inc(m + 1, 0), sum_dec(m + 1, 0);
        ll dp[2001][2001][2]; //compile time allocation, takes close to no time
        for (int i = 0; i <= m; i++) {
            dp[n][i][0] = 1;
            dp[n][i][1] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int start = 1; start <= m; start++) {
                sum_inc[start] =
                    (sum_inc[start - 1] + dp[i + 1][start][0]) % mod;
                sum_dec[start] =
                    (sum_dec[start - 1] + dp[i + 1][start][1]) % mod;
            }
            for (int prevVal = m; prevVal >= 1; prevVal--) {

                // for (int start = prevVal + 1; start <= m; start++) {
                //     dp[i][prevVal][1] = (dp[i][prevVal][1] + dp[i +
                //     1][start][0]) % mod;
                // }
                dp[i][prevVal][1] = (sum_inc[m] - sum_inc[prevVal] + mod) % mod;

                // for (int start = 1; start < prevVal; start++) {
                //     dp[i][prevVal][0] = (dp[i][prevVal][0] + dp[i +
                //     1][start][1]) % mod;
                // }

                dp[i][prevVal][0] = (sum_dec[prevVal - 1]);
            }
        }

        for (int startVal = 1; startVal <= m; startVal++) {
            res = (res + dp[1][startVal][1]) % mod;
            res = (res + dp[1][startVal][0]) % mod;
        }
        return res;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna