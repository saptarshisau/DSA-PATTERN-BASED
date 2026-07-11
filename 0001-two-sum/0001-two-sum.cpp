class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size(); map<int,int> mpp;
        for(int i=0;i<n;i++){
            int a=nums[i];
            int needed= target - a;
            if(mpp.find(needed)!=mpp.end()){
                return {mpp[needed],i};
            }
            mpp[a]=i;
        }
        return {-1,-1};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna