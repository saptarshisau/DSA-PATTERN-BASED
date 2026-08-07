class Solution {
public:
    bool f(string w1, string w2) {
        int cnt = 1;
        int n1 = w1.size(), n2 = w2.size();
        if (n1 + 1 != n2)
            return false;
        for (int i = 0; i < n1; i++) {
            if (cnt == 1) {
                if (w1[i] != w2[i]) {
                    cnt--;
                    if ( w1[i] != w2[i + 1])
                        return false;
                }
            } else {
                if (w1[i] != w2[i + 1])
                    return false;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        vector<int> dp(n, 1);
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (f(words[prev], words[ind]) && dp[ind] < 1 + dp[prev]) {
                    dp[ind] = 1 + dp[prev];
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna