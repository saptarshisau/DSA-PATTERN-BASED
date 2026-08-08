class Solution {
  public:
    void segregate0and1(vector<int> &nums) {
        // code here
         int n=nums.size();
        int z=0,o=n-1;
        while(z<o){
            if(nums[o]){
                o--;
            }else{
                swap(nums[o],nums[z]);
                // o--;
                z++;
            }
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna