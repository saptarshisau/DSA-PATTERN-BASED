class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>> adj(V);
        vector<int> indegree(V);
        for(int i=0;i<V;i++){
            for(auto &it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it: adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};