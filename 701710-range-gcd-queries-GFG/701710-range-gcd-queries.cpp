class Solution {
    public:
      vector<int> arr, seg;
      int n;

      void build(int start, int end, int ind) {
          if (start == end) {
              seg[ind]=arr[start];
              return;
          }
          int mid = start + (end - start) / 2;
          build(start, mid, 2*ind);
          build(mid+1, end, 2*ind+1);
          seg[ind] = gcd(seg[2*ind], seg[2*ind+1]);
      }

      void update(int start, int end, int ind, int idx, int val) {
          if (start == end) {
              seg[ind]= val;
              arr[start] = val;
              return;
          }
          int mid = start + (end - start) / 2;
          if (idx <= mid) update(start, mid, 2*ind, idx, val);
          else update(mid+1, end, 2*ind+1, idx, val);
          seg[ind] = gcd(seg[2*ind], seg[2*ind+1]);
      }

      // returns {min, max} of arr[l..r]
      int query(int start, int end, int l, int r, int ind) {
          if (l > end || r < start) return 0;
          if (l <= start && r >= end) return seg[ind];
          int mid = start + (end - start) / 2;
          int L = query(start, mid, l, r, 2*ind);
          int R = query(mid+1, end, l, r, 2*ind+1);
          return gcd(L,R);
      }

    vector<int> processQueries(vector<int>& a, vector<vector<int>>& queries) {
        // code here
        arr = a;
          n = arr.size();
          seg.assign(4*n,0);
          build(0, n-1, 1);

          vector<int> res;
          for (auto &q : queries) {
              if (q[0] == 0) {
                  int x = query(0, n-1, q[1], q[2], 1);
                  res.push_back(x);
              } else {
                  update(0, n-1, 1, q[1], q[2]);
              }
          }
          return res;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna