class Solution {
public:
    int f(int ind, vector<int>& cost, vector<int>& dp) {
        if (ind < 0)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int n = cost.size();

        return dp[ind] = min(
            ((ind == n) ? 0 : cost[ind]) + f(ind - 1, cost, dp),
            ((ind == n) ? 0 : cost[ind]) + f(ind - 2, cost, dp)
        );
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n + 1, -1);

        return f(n, cost, dp);
    }
};