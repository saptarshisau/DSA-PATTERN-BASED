#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(TreeNode*& root) {
        
        // 0 children
        if (!root->left && !root->right) {
            delete root;
            root = nullptr; 
            return;
        }

        // 1 child
        if (root->left && !root->right) {
            TreeNode* temp = root;
            root = root->left; 
            delete temp;
            return;
        }
        if (root->right && !root->left) {
            TreeNode* temp = root;
            root = root->right; 
            delete temp;
            return;
        }

        // 2 children
        TreeNode* curr = root->left;
        while (curr->right) {
            curr = curr->right;
        }
        
        curr->right = root->right;
        
        TreeNode* temp = root;
        root = root->left; 
        delete temp;
    }

    void searchKeyNode(TreeNode*& root, int key) {
        if (!root)
            return;
            
        if (root->val == key) {
            // Call helper right here! 
            // 'root' is currently a direct reference to the parent's pointer.
            helper(root);
            return;
        }
        
        if (root->val > key) {
            searchKeyNode(root->left, key);
        } else {
            searchKeyNode(root->right, key);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // 'root' is passed by reference all the way down
        searchKeyNode(root, key);
        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna