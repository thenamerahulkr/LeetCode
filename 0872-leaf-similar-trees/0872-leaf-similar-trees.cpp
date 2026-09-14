class Solution {
public:

    void dfs(TreeNode* root, vector<int>& leaves) {

        if (!root)
            return;

        // leaf node
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }

        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> leaves1;
        vector<int> leaves2;

        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    }
};