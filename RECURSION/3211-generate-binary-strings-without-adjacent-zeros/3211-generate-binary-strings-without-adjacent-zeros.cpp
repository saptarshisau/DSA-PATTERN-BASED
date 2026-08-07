class Solution {
public:
    void f(int ind,char prevCh, int n, string curr, vector<string>& res) {

        if (ind == n) {

            res.push_back(curr);

            return;
        }
        if(prevCh=='#' || prevCh=='1')
        f(ind + 1, '0',n, curr + "0", res);

        f(ind + 1,'1', n, curr + "1", res);
    }

    vector<string> validStrings(int n) {
        string curr = "";

        vector<string> res;

        f(0, '#',n, curr, res);

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna