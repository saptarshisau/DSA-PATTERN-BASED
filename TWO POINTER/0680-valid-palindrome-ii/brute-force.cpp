class Solution {
public:
//brute o(n^2)
    bool checkPali(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        bool r=false;
        for(int i=0;i<n;i++){
            string x= s.substr(0,i);
            if(i+1<=n-1) x+=s.substr(i+1,n-1-i);
            r= r|checkPali(x);
        }
        return r;
    }
};
