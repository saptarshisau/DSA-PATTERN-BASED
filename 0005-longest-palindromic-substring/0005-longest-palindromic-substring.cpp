class Solution {
public:
    int f(int l,int r,string s){
        int n=s.size();
        while(l>=0 && r<=n-1 && s[l]==s[r]){
            r++;l--;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
         int n=s.size();
         int maxi=0;
         string res="";
         for(int i=0;i<n;i++){
            int x= max(f(i,i,s),f(i,i+1,s));
            int start = i- (x-1)/2;
            int end = i+ x/2;
            if(x>maxi){
                maxi=x;
                 res=s.substr(start,maxi);
            }
         }
        return res;
    }
};