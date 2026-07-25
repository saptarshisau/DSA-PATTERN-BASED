/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int op(Node* target, map<Node*, Node*>& mp) {
        int level = 0;
        queue<Node*> q;
        q.push(target);
        map<Node*, int> vis;
        vis[target] = 1;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                Node* curr = q.front();
                q.pop();
                if (mp[curr] && !vis[mp[curr]]) {
                    q.push(mp[curr]);
                    vis[mp[curr]] = 1;
                }
                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = 1;
                }
                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = 1;
                }
            }
            // Only increment time if there are more nodes left to process
            // if (!q.empty()) {
                level++;
            // }
        }
        return level-1;
    }

    void bfs(map<Node*, Node*>& mp, Node* root, int targetValue, Node*& targetNode) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if (curr->data == targetValue) {
                targetNode = curr;
            }
            
            if (curr->right) {
                q.push(curr->right);
                mp[curr->right] = curr;
            }
            if (curr->left) {
                q.push(curr->left);
                mp[curr->left] = curr;
            }
        }
    }

    int minTime(Node* root, int target) {
        if (!root) return 0;
        map<Node*, Node*> mp;
        Node* targetNode = NULL;
        
        bfs(mp, root, target, targetNode);
        
        if (!targetNode) return 0; // Target value not found in the tree
        
        int ans = op(targetNode, mp);
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna