class Solution {
  public:
  int dp[45];
  int f(int n){
      if(n==0) return 1;
      if(n==1) return 2;
      if(dp[n]!=-1) return dp[n];
      return dp[n]=f(n-1)+f(n-2);
  }
    int countStrings(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna