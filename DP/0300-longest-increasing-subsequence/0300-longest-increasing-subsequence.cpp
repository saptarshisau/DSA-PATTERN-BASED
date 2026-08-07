class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(temp.empty()|| temp.back()<nums[i]){
                temp.push_back(nums[i]);
            }else{
                int ind= lower_bound(temp.begin(),temp.end(),nums[i]) -temp.begin();
                temp[ind] =nums[i];
            }
        }
        return temp.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna