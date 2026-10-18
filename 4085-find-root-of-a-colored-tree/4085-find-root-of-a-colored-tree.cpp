class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.size();
        auto idx=[](char c){
            switch(c){
                case 'R': return 0;
                case 'B': return 1;
                default: return 2;
            }
        };
        vector<int> indeg(n,0),deg(n,0);
        for(auto &e: edges){
            int u=e[0],v=e[1];
            int cu=idx(colors[u]), cv=idx(colors[v]);
            deg[u]++;deg[v]++;
            if(cu==cv) return -1;
            if((cu+1)%3==cv) indeg[v]++;
            else indeg[u]++;
        }
        int root =-1;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                if(root!=-1) return -1;
                root=i;
            }
            // else if(indeg[i]>1){
            //     return -1;
            // }
        }
        if(root==-1 || deg[root]>2) return -1;
        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna