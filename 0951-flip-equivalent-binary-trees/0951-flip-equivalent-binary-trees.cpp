class Solution {
public:
    bool f(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val) return false;

        bool x = f(a->left,b->left) && f(a->right,b->right);
        bool y = f(a->left,b->right) && f(a->right,b->left);

        return x || y;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return f(root1,root2);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna