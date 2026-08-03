class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size();
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            p.push_back({arr[i][0],arr[i][1]});
        }
        sort(p.begin(),p.end());
        bool b=false;
        for(int i=0;i<n-1;i++){
            if(p[i].second>p[i+1].first) b=true;
        }
        return !b;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna