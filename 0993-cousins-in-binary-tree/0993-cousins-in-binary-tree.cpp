class Solution {
public:
    // same level node and parent diff
    int findLevel(TreeNode* root, int target, int level) {
        if (!root) return -1;
        if (root->val == target)
            return level;
        int left = findLevel(root->left, target, level + 1);
        if (left != -1)
            return left;
        return findLevel(root->right, target, level + 1);
    }
    bool sameParent(TreeNode* root, int x, int y) {
        if (!root)
            return false;
        if (root->left && root->right) {
            if ((root->left->val == x && root->right->val == y) ||
                (root->left->val == y && root->right->val == x)) {
                return true;
            }
        }
        return sameParent(root->left, x, y) || sameParent(root->right, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int levelX = findLevel(root, x, 0);
        int levelY = findLevel(root, y, 0);
        if (levelX != levelY)
            return false;
        if (sameParent(root, x, y))
            return false;
        return true;
    }
};