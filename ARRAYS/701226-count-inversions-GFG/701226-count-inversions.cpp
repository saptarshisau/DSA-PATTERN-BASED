class Solution {
  public:
  

    long long gcnt = 0;

    void merge(vector<int>& nums, int n,
               int l1, int r1, int l2, int r2) {

        int start = l1;
        int end = r2;

        vector<int> temp;

        while(l1 <= r1 && l2 <= r2) {

            if(nums[l1] > nums[l2]) {

                // nums[l1], nums[l1+1] ... nums[r1]
                // are all > nums[l2]
                gcnt += r1 - l1 + 1;

                temp.push_back(nums[l2]);
                l2++;
            }
            else {
                temp.push_back(nums[l1]);
                l1++;
            }
        }

        while(l1 <= r1) {
            temp.push_back(nums[l1]);
            l1++;
        }

        while(l2 <= r2) {
            temp.push_back(nums[l2]);
            l2++;
        }

        // put sorted result back into nums
        for(int i = start; i <= end; i++) {
            nums[i] = temp[i - start];
        }
    }

    void f(vector<int>& nums, int n, int l, int r) {

        if(l >= r)
            return;

        int mid = l + (r-l)/2;

        f(nums, n, l, mid);
        f(nums, n, mid+1, r);

        merge(nums, n, l, mid, mid+1, r);
    }


  int inversionCount(vector<int> &nums) {
      int n=nums.size();
    f(nums, n, 0, n-1);
    return gcnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna