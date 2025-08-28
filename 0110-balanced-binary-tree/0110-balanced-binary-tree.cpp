class Solution {
public:
    int height(TreeNode* temp){
        if(temp == nullptr) return 0;
        return 1 + max(height(temp->left), height(temp->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l = height(root->left);
        int r = height(root->right);
        if(abs(l-r) > 1) return false;
        return isBalanced(root->left) and isBalanced(root->right);
    }
};