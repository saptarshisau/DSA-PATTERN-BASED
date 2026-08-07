class Solution {
  public:
    void segregate0and1(vector<int> &nums) {
        // code here
         int n=nums.size();
        int i=0,j=0;
        while(j<n){
            while(j<n && nums[j]==1){
                j++;
            }
            if(j<n)swap(nums[j],nums[i]);
            i++;
            j++;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna