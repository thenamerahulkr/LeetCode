class Solution {
public:
    void inorder(TreeNode* root, TreeNode* &prev, bool &flag) {
        if (root == NULL) return;
        
        inorder(root->left, prev, flag);
        
        if (prev != NULL) {
            if (root->val <= prev->val) {
                flag = false;
                return;
            }
        }
        
        prev = root;
        inorder(root->right, prev, flag);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        bool flag = true;
        inorder(root, prev, flag);
        return flag;
    }
};