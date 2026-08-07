class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
     
        int n=arr.size();
        int l=0,r=n-1;
        int ans=n;
        while(l<=r){
            int mid= l+(r-l)/2;
            if(arr[mid]>=target){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
 
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna