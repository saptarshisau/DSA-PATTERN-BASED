class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n=arr.size();
        vector<pair<int,int>> p;
        vector<int> diff(2401);
        for(int i=0;i<n;i++){
            p.push_back({arr[i],dep[i]});
        }
        sort(p.begin(),p.end());
        for(auto &it:p){
            diff[it.first]++;
            diff[it.second+1]--;
        }
        int maxi=diff[0],sum=diff[0];
        for(int i=1;i<2400;i++){
            sum+=diff[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna