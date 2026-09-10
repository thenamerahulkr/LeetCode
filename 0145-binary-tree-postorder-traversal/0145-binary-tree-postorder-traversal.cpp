class Solution {
public:
    // recursive O(n)
    void postOrder(TreeNode* root, vector<int>& post) {
        if (root == nullptr)
            return;
        if (root->left)
            postOrder(root->left, post);
        if (root->right)
            postOrder(root->right, post);
        post.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        if (root == nullptr)
            return post;
        postOrder(root,post);
        return post;
    }
};