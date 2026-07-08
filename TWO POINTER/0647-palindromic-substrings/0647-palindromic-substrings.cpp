class Solution {
public:
int f(int l,int r,string s){
        int n=s.size();
        int cnt=0;
        while(l>=0 && r<=n-1 && s[l]==s[r]){
            r++;l--;
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n=s.size();
         int x=0;
        //  string res="";
         for(int i=0;i<n;i++){
         x+= f(i,i,s)+f(i,i+1,s);
         }
        return x;
    }
};