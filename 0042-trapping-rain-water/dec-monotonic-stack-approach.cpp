class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[i]>=height[st.top()]){
                int top_just_small=height[st.top()];
                st.pop();
                if(st.empty()) break;
                int top=st.top();
                int width= i-top-1;
                int h=min(height[top],height[i])-top_just_small;
                ans+=h*width;
            }
            st.push(i);
        }
        return ans;
    }
};
