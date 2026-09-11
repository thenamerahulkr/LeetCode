class Solution {
public:
    void usingStackInReverse(TreeNode* root, vector<int>& post){
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();
            post.push_back(current->val);
            if (current->left)
                st.push(current->left);
            if (current->right)
                st.push(current->right);
        }
        reverse(post.begin(), post.end());
    }
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
        // postOrder(root,post);
        usingStackInReverse(root, post);
        return post;
    }
};