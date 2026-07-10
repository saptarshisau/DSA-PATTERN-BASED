class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size() ;  
         map<vector<int>,int>freq1,freq2 ;
        for(int i=0;i<n;i++){
            vector<int>arr ;
            for(int j=0;j<n;j++){
                arr.push_back(grid[i][j]) ; 
            }
            freq1[arr]++; 
        }
        for(int j=0;j<n;j++){
            vector<int>arr ;
            for(int i=0;i<n;i++){
                arr.push_back(grid[i][j]) ; 
            }
            freq2[arr]++;
        }
        int cnt = 0  ;
        for(auto& it:freq1){
            if(freq2[it.first]>0){
                cnt+= freq2[it.first]*freq1[it.first];  
            }
        }
        return cnt ; 
    }
};