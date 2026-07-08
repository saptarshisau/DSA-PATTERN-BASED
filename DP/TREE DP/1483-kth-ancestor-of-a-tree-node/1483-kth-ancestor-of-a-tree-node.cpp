class TreeAncestor {
public:
    vector<vector<int>> dp;
    int col;
    TreeAncestor(int n, vector<int>& parent) {
        // this->n=n;
        // v=par;
        col = log2(n) + 1;
        dp.resize(n, vector<int>(col, -1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = parent[i];
        }
        for (int j = 1; j < col; j++) {
            for (int node = 0; node < n; node++) {
                if (dp[node][j - 1] != -1) {
                    dp[node][j] = dp[dp[node][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i <= col; i++) {
            if ((k >> i) & 1) {
                node = dp[node][i];
            }
            if (node == -1)
                return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */