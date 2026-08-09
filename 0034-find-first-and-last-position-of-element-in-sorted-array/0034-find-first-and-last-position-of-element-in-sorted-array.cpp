class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int fi = -1, ls = -1;

        // First occurrence
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] >= target) {
                fi = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (fi == -1 || arr[fi] != target)
            return {-1, -1};

        // Last occurrence
        l = 0;
        r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] <= target) {
                ls = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return {fi, ls};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna