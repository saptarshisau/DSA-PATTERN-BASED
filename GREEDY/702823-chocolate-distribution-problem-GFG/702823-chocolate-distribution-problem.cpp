class Solution {
  public:
    int findMinDiff(vector<int>& nums, int m) {
        // code here
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1e9;
        int left=0,right=m-1;
        while(right<n){
            ans=min(ans,nums[right]-nums[left]);
            left++;right++;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna