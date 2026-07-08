class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int cnt1=0,cnt2=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(rating[j]>rating[i]){
                    for(int z=j+1;z<n;z++){
                        if(rating[z]>rating[j]) cnt1++;
                    }
                }else if(rating[j]<rating[i]){
                    for(int z=j+1;z<n;z++){
                        if(rating[z]<rating[j]) cnt2++;
                    }
                }
            }
        }
        return cnt1+cnt2;
    }
};
