class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int cnt=0;
        for(int j=1;j<n-1;j++){
            int leftSmall=0,leftGreater=0,rightSmall=0,rightGreater=0;
            for(int i=0;i<j;i++){
                leftSmall+= (rating[i]<rating[j])? 1:0;
                leftGreater+= (rating[i]>rating[j])? 1:0;
            }
            for(int i=j+1;i<n;i++){
                rightSmall+= (rating[i]<rating[j])? 1:0;
                rightGreater+= (rating[i]>rating[j])? 1:0;
            }
            cnt+= leftSmall*rightGreater + leftGreater*rightSmall;
        }
        return cnt;
    }
};