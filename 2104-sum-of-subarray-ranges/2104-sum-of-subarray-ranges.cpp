class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int maxi=INT_MIN,mini=INT_MAX;
            for(int j=i;j<n;j++){
                maxi=max(nums[j],maxi);
                mini=min(nums[j],mini);
                ans+=maxi-mini;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna