class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp1(n,1),dp2(n,1),g(n);
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if(nums[ind]>nums[prev] && dp1[ind]<1+dp1[prev]){
                    dp1[ind]=1+dp1[prev];
                }
            }
        }
        reverse(nums.begin(),nums.end());
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if(nums[ind]>nums[prev] && dp2[ind]<1+dp2[prev]){
                    dp2[ind]=1+dp2[prev];
                }
            }
        }
        reverse(dp2.begin(),dp2.end());
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1)
            g[i]=dp1[i]+dp2[i]-1;
        }
        return *max_element(g.begin(),g.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna