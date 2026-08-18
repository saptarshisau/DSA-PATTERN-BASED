class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int cnt=__builtin_popcount(ans);
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna