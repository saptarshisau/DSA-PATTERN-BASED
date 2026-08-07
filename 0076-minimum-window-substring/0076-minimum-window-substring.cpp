class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;

        int n = s.size();

        for(auto &it : t) {
            mp[it]++;
        }

        int l = 0, r = 0;
        int ans = INT_MAX;
        int cnt = 0;
        string str = "";

        while(r < n) {

            if(mp[s[r]] > 0)
                cnt++;

            mp[s[r]]--;

            bool found = false;

            while(cnt == t.size()) {
                found = true;

                mp[s[l]]++;

                if(mp[s[l]] > 0)
                    cnt--;

                l++;
            }

            // l has moved ONE position beyond the last valid window
            if(found) {
                int start = l - 1;
                int len = r - start + 1;

                if(len < ans) {
                    ans = len;
                    str = s.substr(start, len);
                }
            }

            r++;
        }

        return str;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna