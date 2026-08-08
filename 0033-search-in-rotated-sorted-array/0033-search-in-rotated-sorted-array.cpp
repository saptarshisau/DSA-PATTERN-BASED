class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();int st=0;int end=n-1;
        while(st<=end){
           int mid=(st+end)/2;
            if(nums[mid]==target) return mid;
            if(nums[st]<=nums[mid]){
                if(nums[st]<=target && target<=nums[mid]){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }

            //right sorted
            else{
                 if(nums[mid]<=target && target<=nums[end]){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna