class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> p;
        for(auto it: boxTypes){
            p.push_back({it[0],it[1]});
        }
        sort(p.begin(),p.end(),[](auto &p1,auto &p2){
            if(p1.second==p2.second) return p1.first<p2.first;
            return p1.second>p2.second;
        });
        int mu=0;
        for(int i=0;i<p.size();i++){
            if(!truckSize) break;
            int nob = p[i].first;
            int noupb = p[i].second;
            int del= (truckSize>=nob)? nob:truckSize;
            mu+= del*noupb;
            truckSize-=del;
        }
        return mu;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna