class RangeFreqQuery {
public:
    vector<vector<int>> pos;
    RangeFreqQuery(vector<int>& arr) {
        pos.resize(10001);                 // values ≤ 10^4
        for (int i = 0; i < arr.size(); i++)
            pos[arr[i]].push_back(i);
    }
    int query(int left, int right, int value) {
        auto &v = pos[value];
        return upper_bound(v.begin(), v.end(), right)
             - lower_bound(v.begin(), v.end(), left);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna