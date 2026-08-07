class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        long long cnt=0;
        unordered_map<long long,long long> mp;
        for(int i=0,j=0;j<n;j++){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]-=1;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
             if(mp.size()==k){
                cnt+=j-i+1;
            }
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna