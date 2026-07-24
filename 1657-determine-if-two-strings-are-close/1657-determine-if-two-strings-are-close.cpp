class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> mp1, mp2;
        map<int, int> nu1, nu2;
        for (auto& ch : word1) {
            mp1[ch]++;
        }
        for (auto& ch : word2) {
            mp2[ch]++;
        }
        for (auto& it : mp1) {
            nu1[it.second]++;
        }
        for (auto& it : mp2) {
            nu2[it.second]++;
        }
        if (mp1 == mp2)
            return true;
        auto it1 = mp1.begin();
        auto it2 = mp2.begin();

        while (it1 != mp1.end() && it2 != mp2.end()) {
            if (it1->first != it2->first)
                return false;
            // if (it1->second != it2->second)
            //     return false;
            ++it1;
            ++it2;
        }
        return nu1 == nu2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna