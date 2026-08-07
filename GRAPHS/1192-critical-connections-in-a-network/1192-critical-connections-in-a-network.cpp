class Solution {
public:
    void dfs(int node, vector<int>& par, vector<int>& vis, vector<int>& low,
             vector<int>& disc, vector<vector<int>>& adj,
             vector<vector<int>>& ans,int count) {
                vis[node]=1;
                disc[node]=low[node]=count;
                for(auto &it: adj[node]){
                    if(it==par[node]) continue;
                    if(vis[it]==-1){
                        par[it]=node;
                        count++;
                        dfs(it, par, vis, low, disc, adj, ans,count);
                        if(low[it]>disc[node]){
                            ans.push_back({node,it});
                        }
                    }
                    low[node]=min(low[node],low[it]);
                }
             }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), ans;
        vector<int> vis(n, -1), low(n, -1), par(n, -1), disc(n, -1);
        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0, par, vis, low, disc, adj, ans,0);
        return ans;
    }
};