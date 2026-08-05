class Solution {
public:
void f(int ind,set<vector<int>> &st, vector<int> &temp,vector<int>& nums){
    if(ind==nums.size()){
        vector<int> temp1=temp;
        sort(temp1.begin(),temp1.end());
        st.insert(temp1);
        return;
    }
    temp.push_back(nums[ind]);
    f(ind+1,st,temp,nums);
    temp.pop_back();
    f(ind+1,st,temp,nums);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        f(0,st,temp,nums);
        vector<vector<int>> ans;
        for(auto it=st.begin();it!=st.end();it++){
            ans.push_back(*it);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna