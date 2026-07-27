class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int hash[26] = {0};
        string req = "croak";
        for (auto& it : croakOfFrogs) {
            hash[it - 'a']++;
            int idx = req.find(it);

            if (idx > 0 && hash[req[idx] - 'a'] > hash[req[idx - 1] - 'a']) {
                return -1;
            }
        }
        int count = hash['c' - 'a'];
        for (auto& it : req) {
            if (count != hash[it - 'a'])
                return -1;
        }
        int cnt_c = 0, maxi = 0;
        for (auto& it : croakOfFrogs) {
            if (it == 'c')
                cnt_c++;
            if (it == 'k')
                cnt_c--;
            maxi = max(maxi, cnt_c);
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna