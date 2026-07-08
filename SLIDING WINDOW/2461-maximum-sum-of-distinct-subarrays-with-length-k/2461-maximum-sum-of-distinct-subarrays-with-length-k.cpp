class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        if (k > n) return 0;

        map<int,int> mp;
        int dup = 0;

        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1) dup++;
        }

        vector<long long> pref(n);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        long long maxi = 0;

        int i = 0, j = k;

        if (dup == 0)
            maxi = max(maxi, pref[k - 1]);

        while (j < n) {

            mp[nums[i]]--;
            if (mp[nums[i]] >= 1) dup--;
            if (mp[nums[i]] == 0) mp.erase(nums[i]);

            mp[nums[j]]++;
            if (mp[nums[j]] > 1) dup++;

            if (dup == 0) {
                long long sum = pref[j] - pref[i] ;
                maxi = max(maxi, sum);
            }

            i++;
            j++;
        }

        return maxi;
    }
};