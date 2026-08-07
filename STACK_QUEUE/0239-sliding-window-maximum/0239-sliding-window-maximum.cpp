class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res;
        deque<pair<int,int>> dq;  // {value, index}

        for(int i = 0; i < n; i++) {

            // 1. Remove elements smaller than nums[i]
            // from the back
            while(!dq.empty() && dq.back().first <= nums[i]) {
                dq.pop_back();
            }

            // 2. Insert current element
            dq.push_back({nums[i], i});

            // 3. Remove front if it's outside current window
            while(!dq.empty() && dq.front().second <= i - k) {
                dq.pop_front();
            }

            // 4. Window of size k has formed
            if(i >= k - 1) {
                res.push_back(dq.front().first);
            }
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna