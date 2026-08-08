class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st=0;int mid=0;int end=nums.size()-1;
        while(mid<=end){
            if(nums[mid]==0){
                swap(nums[st],nums[mid]);
                st++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[end]);
                end--;
            }
            
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna