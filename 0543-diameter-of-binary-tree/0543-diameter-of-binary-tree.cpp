class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diameter = leftHeight + rightHeight;
        int leftdia = diameterOfBinaryTree(root->left);
        int rightdia = diameterOfBinaryTree(root->right);
        return max(diameter, max(leftdia,rightdia));
    }
};