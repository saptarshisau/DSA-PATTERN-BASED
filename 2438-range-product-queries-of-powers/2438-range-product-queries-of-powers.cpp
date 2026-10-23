class Solution {
public:
    long long modpow(long long b, long long e, long long mod) {
        long long r = 1;
        b %= mod;
        while (e > 0) {
            if (e & 1) r = r * b % mod;
            b = b * b % mod;
            e >>= 1;
        }
        return r;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const long long mod = 1000000007;
        vector<long long> power;
        for (int i = 0; i < 31; i++)
            if ((n >> i) & 1) power.push_back(1LL << i);

        int p = power.size();
        vector<long long> pref(p + 1, 1);
        for (int i = 1; i <= p; i++)
            pref[i] = pref[i - 1] * power[i - 1] % mod;   // multiply once

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long inv = modpow(pref[l], mod - 2, mod);  // modular inverse
            ans.push_back(pref[r + 1] * inv % mod);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna