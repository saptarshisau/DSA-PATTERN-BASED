/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void traversal(TreeNode* root,int &ans,map<TreeNode*,TreeNode*> &mp){
    if(!root) return;
    if(mp[mp[root]]){
        if(mp[mp[root]]->val %2==0) ans+=root->val;
    }
    traversal(root->left,ans,mp);
    traversal(root->right,ans,mp);
}
void bfs(TreeNode* root,map<TreeNode*,TreeNode*> &mp){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr= q.front();
        q.pop();
        if(curr->right){
            mp[curr->right]= curr;
            q.push(curr->right);
        }
        if(curr->left){
            mp[curr->left]= curr;
            q.push(curr->left);
        }
    }
}
    int sumEvenGrandparent(TreeNode* root) {
        map<TreeNode*,TreeNode*> mp;
        bfs(root,mp);
        int ans=0;
        traversal(root,ans,mp);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna