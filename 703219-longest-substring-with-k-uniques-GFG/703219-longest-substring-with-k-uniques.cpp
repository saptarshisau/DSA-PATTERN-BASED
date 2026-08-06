class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int ans = -1;

        int l=0,r=0;
        map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            if(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            if(mp.size()==k) ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna