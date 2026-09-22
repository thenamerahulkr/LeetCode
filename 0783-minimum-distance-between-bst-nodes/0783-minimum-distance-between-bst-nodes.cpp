class Solution {
public:
    void inorder(TreeNode* root, int& prev, int& ans) {
        if (!root)
            return;

        inorder(root->left, prev, ans);

        if (prev != -1) {
            ans = min(ans, root->val - prev);
        }

        prev = root->val;

        inorder(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        int ans = INT_MAX;

        inorder(root, prev, ans);

        return ans;
    }
};