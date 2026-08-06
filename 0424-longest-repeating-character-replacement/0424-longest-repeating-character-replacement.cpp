class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        map<char,int> findm;
        for(char ch : s)
            findm[ch]++;

        int ans = 0;

        for(auto &it : findm) {

            char ch = it.first;

            int l = 0, r = 0;
            int curr_diff = 0;

            while(r < n) {

                if(s[r] != ch)
                    curr_diff++;

                while(curr_diff > k) {
                    if(s[l] != ch)
                        curr_diff--;

                    l++;
                }

                ans = max(ans, r - l + 1);

                r++;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna