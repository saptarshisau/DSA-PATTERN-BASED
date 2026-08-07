class Solution {
  public:
    void segregateEvenOdd(vector<int>& arr) {
        // code here
         int n=arr.size();
        vector<int> o,e;
        for(int i=0;i<n;i++){
            if(arr[i]%2)o.push_back(arr[i]);
            else e.push_back(arr[i]);
        }
        sort(begin(o),end(o));
        sort(begin(e),end(e));
          for(int i=0;i<e.size();i++){
              arr[i]=e[i];
          }
          int x=e.size();
          for(int i=0;i<o.size();i++){
              arr[x+i]=o[i];
          }
        //   return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna