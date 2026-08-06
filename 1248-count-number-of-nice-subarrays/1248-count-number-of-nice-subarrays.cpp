class Solution {
public:

    int atMost(vector<int>& nums, int k) {
        if(k < 0) return 0;

        int l = 0, r = 0;
        int odd = 0;
        int ans = 0;

        while(r < nums.size()) {

            if(nums[r] % 2)
                odd++;

            while(odd > k) {
                if(nums[l] % 2)
                    odd--;

                l++;
            }

            ans += r - l + 1;

            r++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna