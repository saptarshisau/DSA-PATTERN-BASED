class Solution {
public:
    int cntStd(vector<int>&arr, int pages){
        int students=1;
        long long currentTotalpg=0;
        for(int i=0;i<arr.size();i++){
            if(currentTotalpg+arr[i]<=pages) currentTotalpg+=arr[i];
            else {
                students+=1;
               currentTotalpg=arr[i];
            }
        }
        return students;
    }
     int findPages(vector<int> &arr, int k) {
        // code here
        int ans=-1;
        if (k>arr.size()) return -1;
        int low =*max_element(arr.begin(),arr.end());
        int high= accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid= (high+low)/2;
            int noStd=cntStd(arr,mid);
            if(noStd>k) {
               low=mid+1;
                
            }
            else {
               high=mid-1;
                
                
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna