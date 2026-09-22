class Solution {
public:
    bool validate(TreeNode* root, long long min, long long max) {
        if (!root)
            return true;
        // if(!root->left && !root->right) return true;
        if (root->val <= min || root->val >= max)
            return false;
        return validate(root->left, min, root->val) &&
               validate(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        // if(!root) return true;
        // if(!root->left && !root->right) return true;
        // int rootValue = root->val;

        // if(root->left != nullptr && root->left->val >= rootValue ||
        // root->right != nullptr &&root->right->val <= rootValue) return false;
        // return isValidBST(root->left) && isValidBST(root->right);
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};