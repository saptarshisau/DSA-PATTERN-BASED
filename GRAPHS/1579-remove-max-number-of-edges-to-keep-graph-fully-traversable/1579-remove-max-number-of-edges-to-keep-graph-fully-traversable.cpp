class Solution {
public:
    class DSU {
    public:
        vector<int> par, rank;
        int component;
        
        DSU(int n) {
            component = n; 
            par.resize(n + 1, 0);
            for (int i = 0; i <= n; i++) {
                par[i] = i;
            }
            rank.resize(n + 1, 0);
        }
        
        int find_par(int node) {
            if (par[node] == node)
                return node;
            return par[node] = find_par(par[node]);
        }
        
        void U(int node1, int node2) {
            int par1 = find_par(node1), par2 = find_par(node2);
            if (par1 == par2) return;
            
            if (rank[par1] > rank[par2]) {
                par[par2] = par1;
            } else if (rank[par1] < rank[par2]) {
                par[par1] = par2;
            } else {
                rank[par1]++;
                par[par2] = par1;
            }
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        
        sort(edges.begin(), edges.end(),
             [](auto& vec1, auto& vec2) { return vec1[0] > vec2[0]; });
             
        DSU alice(n);
        DSU bob(n);
        
        for (auto& it : edges) {
            int type = it[0];
            int node_x = it[1];
            int node_y = it[2];
            
            if (type == 3) {
                bool used = false;
                
                if (bob.find_par(node_x) != bob.find_par(node_y)) {
                    bob.U(node_x, node_y);
                    bob.component--;
                    used = true;
                }

                if (alice.find_par(node_x) != alice.find_par(node_y)) {
                    alice.U(node_x, node_y);
                    alice.component--;
                    used = true;
                }

                if (used) cnt++;
                
            } else if (type == 1) {
                if (alice.find_par(node_x) != alice.find_par(node_y)) {
                    alice.U(node_x, node_y);
                    alice.component--;
                    cnt++;
                }
            } else {
                if (bob.find_par(node_x) != bob.find_par(node_y)) {
                    bob.U(node_x, node_y);
                    bob.component--;
                    cnt++;
                }
            }
        }
        
        if (bob.component == 1 && alice.component == 1) {
            return edges.size() - cnt;
        }
        
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna