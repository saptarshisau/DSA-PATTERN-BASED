class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
int l = 0, r = 0;
int ans = 0, curr = 0;

while(r < n) {

    if(nums[r] == 0)
        curr++;

    if(curr > k) {
        if(!nums[l]) curr--;
        l++;
    }

    ans = max(ans, r - l+1 );

    r++;
}

return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna