class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> l(n),r(n);
        l[0]=1;r[n-1]=1;
        int cnt1=1,cnt2=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                cnt1++;
                l[i]=cnt1;
            }else{
                l[i]=1;
                cnt1=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                cnt2++;
                r[i]=cnt2;
            }else{
                r[i]=1;
                cnt2=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(l[i],r[i]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna