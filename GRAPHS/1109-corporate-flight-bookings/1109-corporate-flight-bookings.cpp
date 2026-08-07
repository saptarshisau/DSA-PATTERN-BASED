class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> temp(n+1,0);
        int m=bookings.size();
        for(int i=0;i<m;i++){
            temp[bookings[i][0]-1]+=bookings[i][2];
            temp[bookings[i][1]]-=bookings[i][2];
        }
        vector<int> pref(n,0);
        pref[0]=temp[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+temp[i];
        }
        return pref;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna