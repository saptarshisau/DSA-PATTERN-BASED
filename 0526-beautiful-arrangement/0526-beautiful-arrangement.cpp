class Solution {
public:
    int cnt = 0;

    void f(int ind, vector<int>& nums) {
        if (ind == nums.size()) {
            cnt++;
            return;
        }

        for (int i = ind; i < nums.size(); i++) {

            // nums[i] will be placed at position (ind + 1)
            if (nums[i] % (ind + 1) != 0 && (ind + 1) % nums[i] != 0)
                continue;

            swap(nums[i], nums[ind]);

            f(ind + 1, nums);

            swap(nums[i], nums[ind]);
        }
    }

    int countArrangement(int n) {
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
            nums[i] = i + 1;

        f(0, nums);

        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna