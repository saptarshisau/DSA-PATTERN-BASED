#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        for(int num=0;num<(int)pow(2,n);num++){
            bool b=true;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(((1<<i)&num)==0){
                    if(cnt==1){
                        b=false;
                        break;
                    } else cnt++;
                } else {
                    cnt=0;
                }
            }
            if(b) ans.push_back(bitset<20>(num).to_string().substr(20 - n));
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna