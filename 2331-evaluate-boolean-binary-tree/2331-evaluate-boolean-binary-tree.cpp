class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val == 0) return false;
        if(root->val == 1) return true;
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        if(root->val == 3){
            return l and r;
        }
        if(root->val == 2){
            return l or r;
        }
        return false;
    }
};