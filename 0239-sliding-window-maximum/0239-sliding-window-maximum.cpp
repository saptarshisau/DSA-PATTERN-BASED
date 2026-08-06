class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> res;
        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            if(!dq.empty() && i-k>=dq.front()){
                dq.pop_front();
            }
            
            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna