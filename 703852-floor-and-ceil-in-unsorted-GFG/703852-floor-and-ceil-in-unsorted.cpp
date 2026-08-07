class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int l=0,r=n-1;
        int floor=-1,ceil=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==x){
                ceil=x;floor=x;
                break;
            }
            if(arr[mid]<x){
                floor=arr[mid];
                l=mid+1;
            }else{
                ceil=arr[mid];
                r=mid-1;
            }
        }
        return {floor,ceil};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna