class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0,ans=0;
        map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            while(mp.size()==3){
                ans+=n-r;
                mp[s[l]]--;
                if(!mp[s[l]]) mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna