class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        // Code here
         int n=nums.size();
        vector<int> dp(n,1),hash(n,0),prin;
        for(int i=0;i<n;i++) hash[i]=i;
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if(nums[ind]>nums[prev] && dp[ind]<1+dp[prev]){
                    dp[ind]=1+dp[prev];
                    hash[ind]=prev;
                }
            }
        }
        int iniInd=max_element(dp.begin(),dp.end())- dp.begin();
        prin.push_back(nums[iniInd]);
        while(iniInd!=hash[iniInd]){
            prin.push_back(nums[hash[iniInd]]);
            iniInd=hash[iniInd];
        }
        reverse(prin.begin(), prin.end());
        return prin;
    
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna