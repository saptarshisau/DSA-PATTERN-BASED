/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void op(TreeNode* target, int k,map<TreeNode*,TreeNode*> &mp,vector<int>& res){
    if(k==0) {res.push_back(target->val);return;}
    int level=0;
    queue<TreeNode*> q;
     q.push(target);
     map<TreeNode*,int> vis;
     vis[target]=1;
     while(level!=k && !q.empty()){
        int n=q.size();

        while(n--){
            TreeNode* curr=q.front();
            q.pop();
            if(mp[curr] && !vis[mp[curr]]){
                if(level==k-1) res.push_back(mp[curr]->val);
                q.push(mp[curr]);
                vis[mp[curr]]=1;
            }
            if(curr->right && !vis[curr->right]){
                if(level==k-1) res.push_back(curr->right->val);
                q.push(curr->right);
                vis[curr->right]=1;
            }
            if(curr->left && !vis[curr->left]){
                if(level==k-1) res.push_back(curr->left->val);
                q.push(curr->left);
                vis[curr->left]=1;
            }
        }
        level++;
     }
}
void bfs(map<TreeNode*,TreeNode*> &mp,TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr->right) {
            q.push(curr->right);
            mp[curr->right]=curr;
        }
        if(curr->left) {
            q.push(curr->left);
            mp[curr->left]=curr;
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> mp;
        bfs(mp,root);
        vector<int> ans;
        op(target,k,mp,ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna