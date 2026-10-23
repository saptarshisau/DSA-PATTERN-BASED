class NumArray {
public:
    vector<int> arr;
    vector<int> seg;
    int n;
    void build(int start,int end,int ind){
        if(start==end){
            seg[ind]=arr[start];
            return;
        }
        int mid= start+(end-start)/2;
        build(start,mid,2*ind);
        build(mid+1,end,2*ind+1);
        seg[ind] = seg[2*ind] + seg[2*ind+1];
    }
    void callUpdate(int start,int end,int ind,int queryInd,int val){
        if(start==end){
            seg[ind]=val;
            arr[start]=val;
            return;
        }
        int mid= start+(end-start)/2;
        if(queryInd<=mid) callUpdate(start,mid,2*ind,queryInd,val);
        else callUpdate(mid+1,end,2*ind+1,queryInd,val);
        seg[ind] = seg[2*ind] + seg[2*ind+1];
    }
    int callRangeSum(int start,int end,int l,int r,int ind){
        if(l>end || r<start) return 0;
        if(l<=start && r>=end) return seg[ind];
        int mid= start+(end-start)/2;
        int ls=callRangeSum(start,mid,l,r,2*ind);
        int rs=callRangeSum(mid+1,end,l,r,2*ind+1);
        return ls+rs;
    }
    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        seg.resize(4*n);
        build(0,n-1,1);
    }
    void update(int index, int val) {
        callUpdate(0,n-1,1,index,val);
    }
    int sumRange(int left, int right) {
        return callRangeSum(0,n-1,left,right,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna