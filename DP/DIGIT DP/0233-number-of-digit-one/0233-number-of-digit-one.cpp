class Solution {
public:
typedef long long ll;
    ll dp[2][10][10];
ll f(string &s, int tight, int idx, int cnt_1)
{
    if (idx == static_cast<int>(s.size()))
        return cnt_1;
    if (dp[tight][idx][cnt_1] != -1)
        return dp[tight][idx][cnt_1];
    ll lb = 0;
    ll ub = (tight == true) ? (s[idx] - '0') : 9;
    ll res = 0;
    for (int i = lb; i <= ub; i++)
    {
        res += f(s, (tight && i == ub) ? 1 : 0, idx + 1, cnt_1 +((i==1)? 1:0));
    }
    return dp[tight][idx][cnt_1] = res;
}
    int countDigitOne(int n) {
        if(n==0) return 0;
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return f(s,1,0,0);
    }
};