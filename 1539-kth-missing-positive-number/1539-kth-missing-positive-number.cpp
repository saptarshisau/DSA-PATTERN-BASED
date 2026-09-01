class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size(), cnt=0;
        int curr=-1;
        vector<int> vis(2001);
        for(int i=0;i<n;i++){
            vis[arr[i]]=1;
        }
        for(int i=1;i<2001;i++){
            if(!vis[i]){cnt++;curr=i;}
            if(cnt==k)break;
        }
        return curr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna