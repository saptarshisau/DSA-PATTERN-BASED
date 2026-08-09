class Solution {
  public:
    int longestSubarray(vector<int>& nums, int k) {
        // code here
        int n=nums.size();
        // [2,0,0,3]
        map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        int len=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())len=max(len,i-mp[sum-k]);
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return len;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna