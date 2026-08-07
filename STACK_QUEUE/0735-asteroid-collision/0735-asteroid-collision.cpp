class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                if (!st.empty() && st.top() >= 0) {
                    while (!st.empty() && st.top() < abs(nums[i]) && (st.top()>0)) {
                        st.pop();
                    }
                    if (!st.empty() && st.top() == abs(nums[i])) {
                        st.pop();
                        continue;
                    }
                }
                if (st.empty() || st.top() < 0)
                    st.push(nums[i]);
            } else {
                st.push(nums[i]);
            }
            
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna