class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=1e9;
        int curr_s=0;
        int l=0,r=0;
        while(r<n){
            curr_s+=nums[r];
            while(curr_s>=target){
                curr_s-=nums[l];
                l++;
                ans=min(ans,r-l+2);
            }
            
            r++;
        }
        return ans==1e9?0:ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna