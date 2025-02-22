class Solution {
public:
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1 + max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(abs(leftHeight-rightHeight)>1)return false;
        return isBalanced(root->left) and isBalanced(root->right);
    }
};