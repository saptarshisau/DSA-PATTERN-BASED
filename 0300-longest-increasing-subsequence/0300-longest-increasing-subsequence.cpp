class Solution {
public:
    int dp[2501][2501];
    int f(int ind,int prev_ind,vector<int>& nums,int n){
        if(ind==n)return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int take=0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
         take= 1+f(ind+1,ind,nums,n);
        int not_take=0+f(ind+1,prev_ind,nums,n);
        return dp[ind][prev_ind+1]= max(not_take,take);
    }
    int lengthOfLIS(vector<int>& nums) {
      memset(dp, -1, sizeof(dp));
     int n=nums.size();
    return f(0,-1,nums,n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna