class Solution {
public:
    bool usingDfs(TreeNode* left, TreeNode* right){
        if (!left && !right) return true;
        if (!left || !right) return false;
        if(left->val != right->val) return false;
        return usingDfs(left->left, right->right) && usingDfs(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return usingDfs(root->left, root->right);
    }
};