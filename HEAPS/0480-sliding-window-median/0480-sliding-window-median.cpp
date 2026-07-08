class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
       
        int n = nums.size();
        vector<double> res(n - k + 1);
        priority_queue<int, vector<int>, greater<int>> minh;
        priority_queue<int> maxh;
        map<int, int> mp;
        for (int i = 0; i < k; i++) {
            int num = nums[i];
            if (maxh.empty() || num <= maxh.top()) {
                maxh.push(num);
            } else {
                minh.push(num);
            }
            if (maxh.size() > minh.size() + 1)
            // unsigned size thats y maxh.size()-minh.size()  >  1  cant be
            // used//
            {
                minh.push(maxh.top());
                maxh.pop();
            } else if (maxh.size() < minh.size()) {
                maxh.push(minh.top());
                minh.pop();
            }
        }
        res[0] = k % 2 == 0 ? ((double)maxh.top() + minh.top()) / 2.0 : maxh.top();
        int j = 1;
        for (int i = k; i < n; i++) {
            int add = nums[i], remove = nums[i - k];
            mp[remove]++;
            int cnt = 0;
            // maxheap add +1 else -1
            // minheap add -1 else +1
            //  to cnt
            if (add <= maxh.top()) {
                maxh.push(add);
                cnt++;
            } else {
                minh.push(add);
                cnt--;
            }

            if (remove <= maxh.top()) {
                cnt--;
            } else {
                cnt++;
            }
            if (cnt > 0) {
                int x = maxh.top();
                maxh.pop();
                minh.push(x);
            } 
            else if(cnt<0){
                int y = minh.top();
                minh.pop();
                maxh.push(y);
            }
            while (!maxh.empty() && mp[maxh.top()]) {
                mp[maxh.top()]--;
                maxh.pop();
            }
            while (!minh.empty() && mp[minh.top()]) {
                mp[minh.top()]--;
                minh.pop();
            }
            
            res[j] = k % 2 == 0 ? ((double)maxh.top() + minh.top()) / 2.0 : maxh.top();
            j++;
        }
        return res;
    }
};