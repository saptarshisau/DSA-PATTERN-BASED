class Solution {
public:
    bool f(int mid,vector<int>& nums, int maxOperations){
        long long cnt=0;
        for(auto &num:nums){
            if(num%mid==0)cnt+= num/mid-1;
            else cnt+=num/mid;    
        }
        return cnt<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=1,r=nums[n-1];
        int ans=0;
        while(l<=r){
            int mid =l+(r-l)/2;
            if(f(mid,nums,maxOperations)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna