class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned long long> prev(m + 1, 0);
        prev[0] = 1;

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = m; ind2 >= 1; ind2--) {

                if (s[ind1 - 1] == t[ind2 - 1]) {
                    prev[ind2] = prev[ind2 - 1] + prev[ind2];
                } else
                    prev[ind2] = prev[ind2];
            }
        }
        return (int)prev[m];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna