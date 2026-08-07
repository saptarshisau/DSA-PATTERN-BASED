class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};

        int i = 0, j = 0;
        int cnt = 0;
        int miniLen = INT_MAX;
        int stInd = -1;

        for(int i = 0; i < t.size(); i++)
            hash[t[i]]++;

        while(j < s.size()) {

            if(hash[s[j]] > 0) cnt++;
            hash[s[j]]--;

            while(cnt == t.size()) {

                if(j - i + 1 < miniLen) {
                    miniLen = j - i + 1;
                    stInd = i;
                }

                hash[s[i]]++;

                if(hash[s[i]] > 0) cnt--;
                i++;
            }
            j++;
        }

        if(stInd == -1) return "";
        return s.substr(stInd, miniLen);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna