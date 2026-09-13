class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> visited;
    void fillParent(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            parent[root->left] = root;
            fillParent(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            fillParent(root->right);
        }
    }
    TreeNode* searchNode(TreeNode* root, int start) {
        if (!root)
            return nullptr;
        if (root->val == start)
            return root;
        TreeNode* left = searchNode(root->left, start);
        if (left)
            return left;
        return searchNode(root->right, start);
    }
    int levelOrderTraversal(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        visited.insert(root);
        int currentLevel = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* current = q.front();
                q.pop();
                if (current->left && !visited.count(current->left)) {
                    visited.insert(current->left);
                    q.push(current->left);
                }
                if (current->right && !visited.count(current->right)) {
                    visited.insert(current->right);
                    q.push(current->right);
                }
                if (parent.find(current) != parent.end() &&
                    parent[current] != nullptr &&
                    !visited.count(parent[current])) {
                    visited.insert(parent[current]);
                    q.push(parent[current]);
                }
            }
            currentLevel++;
        }
        return currentLevel - 1;
    }
    int amountOfTime(TreeNode* root, int start) {
        parent[root] = nullptr;
        fillParent(root);
        TreeNode* targetStart = searchNode(root, start);
        return levelOrderTraversal(targetStart);
    }
};