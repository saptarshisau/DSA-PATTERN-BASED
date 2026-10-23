class Solution {
  public:
    vector<int> arr, segMax, segMin;
    int n;

    void build(int start, int end, int ind) {
        if (start == end) {
            segMax[ind] = segMin[ind] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(start, mid, 2*ind);
        build(mid+1, end, 2*ind+1);
        segMax[ind] = max(segMax[2*ind], segMax[2*ind+1]);
        segMin[ind] = min(segMin[2*ind], segMin[2*ind+1]);
    }

    void update(int start, int end, int ind, int idx, int val) {
        if (start == end) {
            segMax[ind] = segMin[ind] = val;
            arr[start] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) update(start, mid, 2*ind, idx, val);
        else update(mid+1, end, 2*ind+1, idx, val);
        segMax[ind] = max(segMax[2*ind], segMax[2*ind+1]);
        segMin[ind] = min(segMin[2*ind], segMin[2*ind+1]);
    }

    // returns {min, max} of arr[l..r]
    pair<int,int> query(int start, int end, int l, int r, int ind) {
        if (l > end || r < start) return {INT_MAX, INT_MIN};
        if (l <= start && r >= end) return {segMin[ind], segMax[ind]};
        int mid = start + (end - start) / 2;
        auto L = query(start, mid, l, r, 2*ind);
        auto R = query(mid+1, end, l, r, 2*ind+1);
        return {min(L.first, R.first), max(L.second, R.second)};
    }

    vector<vector<int>> rangeMinMaxQueries(vector<int>& a,
                                           vector<vector<int>>& queries) {
        arr = a;
        n = arr.size();
        segMax.assign(4*n, INT_MIN);
        segMin.assign(4*n, INT_MAX);
        build(0, n-1, 1);

        vector<vector<int>> res;
        for (auto &q : queries) {
            if (q[0] == 1) {
                auto [mn, mx] = query(0, n-1, q[1], q[2], 1);
                res.push_back({mn, mx});
            } else {
                update(0, n-1, 1, q[1], q[2]);
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna