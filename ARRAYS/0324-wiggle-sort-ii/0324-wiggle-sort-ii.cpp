class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        sort(begin(nums),end(nums));
        int small_ptr=(n-1)/2, large_ptr=n-1;
        for(;small_ptr>=0;){
            
            res.push_back(nums[small_ptr--]);
            if(large_ptr>(n-1)/2)res.push_back(nums[large_ptr--]);
        }
        nums=res;
    }
};