class Solution {
public:
    typedef long long ll;
    bool checkSubarraySum(vector<int>& nums, int k) {
        //prefsum with storing remainders
        int n=nums.size();
        if(n<2) return false;
        map<int,int> mp;
        mp[0]=-1;
        ll pref=0;
        for(int i=0;i<n;i++){
            pref+=nums[i];
            int rem=pref%k;
            if(mp.find(rem)!=mp.end()){
                if(i- mp[rem]>=2) return true;
            }else mp[rem]=i;
        }
        return false;
    }
};