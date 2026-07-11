class Solution {
  public:
    void dfs(int node, vector<int>& par, vector<int>& vis, vector<int>& low,
             vector<int>& disc, vector<vector<int>>& adj,
             int c,int d,bool &ans,int count) {
                vis[node]=1;
                disc[node]=low[node]=count;
                for(auto &it: adj[node]){
                    if(it==par[node]) continue;
                    if(vis[it]==-1){
                        par[it]=node;
                        count++;
                        dfs(it, par, vis, low, disc, adj, c,d,ans,count);
                        low[node]=min(low[node],low[it]);

            if(low[it]>disc[node]){
                if((node==c && it==d)||(node==d && it==c))
                    ans=true;
            }
        }
        else{
            low[node]=min(low[node],disc[it]);
        }
                }
             }
    bool isBridge(int n, vector<vector<int>> &connections, int c, int d) {
        // Code here
         vector<vector<int>> adj(n);
         bool ans=false;
        vector<int> vis(n, -1), low(n, -1), par(n, -1), disc(n, -1);
        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            
        if(vis[i]==-1)
        dfs(i, par, vis, low, disc, adj, c,d,ans,0);
            
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna