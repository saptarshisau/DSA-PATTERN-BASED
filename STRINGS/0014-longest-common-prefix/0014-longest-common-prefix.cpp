class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //trashest brute force
        if (strs.size() == 1) return strs[0];
        
        int n=strs.size();
        int maxi=201;
        for(int i=0;i<n-1;i++){
            string s1=strs[i];
            string s2=strs[i+1];
            size_t j=0;
            for(;j<min(s1.size(),s2.size());j++){
                if(s1[j]!=s2[j]) break;
            }
            maxi=min(maxi,(int)j);
        }
        string s="";
        for(int i=0;i<maxi;i++){
            s+=strs[0][i];
        }
        return s;
    }
};