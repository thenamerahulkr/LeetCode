class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) 
            return root;
        TreeNode* leftSearch = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSearch = lowestCommonAncestor(root->right, p, q);
        if (leftSearch && rightSearch)
            return root;
        if (!rightSearch)
            return leftSearch;
        return rightSearch;
    }
};