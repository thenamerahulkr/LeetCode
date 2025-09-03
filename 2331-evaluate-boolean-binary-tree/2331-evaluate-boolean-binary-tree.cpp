class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val == 0) return false;
        if(root->val == 1) return true;
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        if(root->val == 3){
            if(l and r) return true;
            else return false;
        }
        if(root->val == 2){
            if(l or r) return true;
            else return false;
        }
        return false;
    }
};