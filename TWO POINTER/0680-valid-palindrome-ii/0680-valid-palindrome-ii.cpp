class Solution {
public:
    bool checkPali(int l,int r,string s){
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            if(s[l]!=s[r]){
                return checkPali(l,r-1,s)||checkPali(l+1,r,s);
            }
            l++;r--;
        }
        return true;
    }
};