class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int leftsum = accumulate(nums.begin(),nums.begin()+k,0);
        int maxi= leftsum;
        int rightsum = 0;
        int l=k-1, r=n-1;
        while(r>=n-k){
            leftsum-=nums[l];
            rightsum+=nums[r];
            maxi=max(maxi,leftsum+rightsum);
            r--;
            l--;
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna