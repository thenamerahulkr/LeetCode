class Solution {
public:
    bool preOrderTraversal(TreeNode* root, int uniValue) {
        if (!root)
            return true;
        if (root->val != uniValue)
            return false;
        bool leftResult = preOrderTraversal(root->left, uniValue);
        bool rightResult = preOrderTraversal(root->right, uniValue);
        return leftResult && rightResult;
    }
    bool levelOrderTraversal(TreeNode* root) {
        if (!root)
            return true;
        int uniValue = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->val != uniValue) {
                return false;
            }
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        int uniValue = root->val;
        return levelOrderTraversal(root);
        // return preOrderTraversal(root, uniValue);
    }
};