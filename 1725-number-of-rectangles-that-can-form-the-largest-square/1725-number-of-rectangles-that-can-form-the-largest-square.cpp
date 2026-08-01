class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        map<int,int> mp;
        int maxi=0;
        for(int i=0;i<n;i++){
            int l=rectangles[i][0];
            int w=rectangles[i][1];
            int taken=min(l,w);
            mp[taken]++;
            maxi= max(maxi,taken);
        }
        return mp[maxi];

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna