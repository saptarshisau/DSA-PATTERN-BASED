class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n == 0) return 0;
        int l=0,r=0;
        int maxi=0;
        map<char,int> mp;
        while(r<n){
            if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
           mp[s[r]]=r;
           maxi=max(maxi,r-l+1);
           r++;
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna