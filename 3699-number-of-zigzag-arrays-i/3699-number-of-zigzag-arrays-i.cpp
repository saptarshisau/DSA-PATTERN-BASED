class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        ll res = 0LL;
        
        vector<vector<int>> next_dp(m + 1, vector<int>(2, 1));
        vector<vector<int>> curr_dp(m + 1, vector<int>(2, 0));
        vector<ll> sum_inc(m + 1, 0);
        vector<ll> sum_dec(m + 1, 0);

        for (int i = n - 1; i >= 1; i--) {
            for (int start = 1; start <= m; start++) {
                sum_inc[start] = (sum_inc[start - 1] + next_dp[start][0]) % mod;
                sum_dec[start] = (sum_dec[start - 1] + next_dp[start][1]) % mod;
            }
            
            for (int prevVal = m; prevVal >= 1; prevVal--) {
                curr_dp[prevVal][1] = (sum_inc[m] - sum_inc[prevVal] + mod) % mod;
                curr_dp[prevVal][0] = sum_dec[prevVal - 1];
            }
            
            next_dp = curr_dp;
        }

        for (int startVal = 1; startVal <= m; startVal++) {
            res = (res + next_dp[startVal][1]) % mod;
            res = (res + next_dp[startVal][0]) % mod;
        }
        
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna