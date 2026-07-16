class Solution {
  public:
  void f(int n,vector<int> &ans) {
    
    ans.push_back(1);
    for(int multiplier=2;multiplier<=n;multiplier++){
        int carry=0;
        for(int j=0;j<ans.size();j++){
            int num=ans[j]*multiplier + carry;
              carry=num/10;
            ans[j]=num%10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }
    }
    
}
    vector<int> factorial(int n) {
        // code here
        vector<int> ans;
    f(n,ans);
    reverse(ans.begin(),ans.end());
    return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna