class Solution {
public:
typedef long long ll;
ll dp[2][11][16][2];
    ll f(string &s,int tight,int prev,int idx,int lead_zero,int k){
        if(idx==s.size())return 1;
        if(dp[tight][prev][idx][lead_zero]!=-1) return dp[tight][prev][idx][lead_zero];
        ll lb=0;
        ll ub = (tight==true)? (s[idx]-'0') : 9;
        ll res=0;
        for(int i=lb;i<=ub;i++){
            if(abs(prev-i)>k && !lead_zero) continue;
            res+=f(s,(tight && i==ub)? 1:0, i, idx+1,(lead_zero && i==0)? 1:0,k);
        }
        return dp[tight][prev][idx][lead_zero]=res;
    }
    long long goodIntegers(long long l, long long r, int k) {
        string _l=to_string(l-1);
        string _r=to_string(r);
        //index, prev, tight(bool), leading zero(bool)
        memset(dp,-1,sizeof(dp));
        ll f1=f(_r,1,10,0,1,k);
        memset(dp,-1,sizeof(dp));
        ll f2=f(_l,1,10,0,1,k);
        return  f1-f2;
    }
};