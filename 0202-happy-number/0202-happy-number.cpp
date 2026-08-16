class Solution {
public:
    int f(int n){
int sum=0;
        while(n){
int rem=n%10;
            sum+=rem*rem;
            n/=10;
}
        return sum;
}

    bool isHappy(int n) {
        map<int,int> mp;
        bool b=true;
        while(n!=1){
            if(mp.find(n)!=mp.end()){b=false;break;}
            mp[n]++;
            n=f(n);
        }
return b;
    }
};