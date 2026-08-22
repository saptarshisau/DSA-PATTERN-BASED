class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;int high=arr.size()-1;
        int ans=0;
        while(low<=high){
            int mid= low +((high-low)/2);
            int missing =arr[mid]-(mid+1);
            if(missing<k){ ans=mid+1;low=mid+1;}
            else high=mid-1;
        }
        return low+k;
    }
};