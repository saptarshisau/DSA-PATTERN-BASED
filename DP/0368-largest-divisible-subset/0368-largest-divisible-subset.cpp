class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),maxi=-1e9,ini=-1;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n),prin;
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev=0;prev<ind;prev++){
                if(nums[ind]%nums[prev]==0 && dp[ind]<1+dp[prev]){
                    dp[ind]=1+dp[prev];
                    hash[ind]=prev;
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                ini=ind;
            }
        }
        prin.push_back(nums[ini]);
        while(hash[ini]!=ini){
            prin.push_back(nums[hash[ini]]);
            ini=hash[ini];
        }
        return prin;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna