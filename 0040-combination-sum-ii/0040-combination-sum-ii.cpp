class Solution {
public:
    void f(int ind, vector<int>& temp, vector<vector<int>>& ans,
           vector<int>& nums, int target) {
        int n = nums.size();

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < n; i++) {
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            if (target >= nums[i]) {
                temp.push_back(nums[i]);
                f(i + 1, temp, ans, nums, target - nums[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, temp, ans, nums, target);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna