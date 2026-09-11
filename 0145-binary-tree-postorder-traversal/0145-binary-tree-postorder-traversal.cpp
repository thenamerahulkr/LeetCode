class Solution {
public:
    void usingTwoStack(TreeNode* root, vector<int>& post){
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode* current = s1.top();
            s1.pop();
            s2.push(current);
            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }
        while (!s2.empty()) {
            post.push_back(s2.top()->val);
            s2.pop();
        }
    }
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
        usingTwoStack(root, post);
        // usingStackInReverse(root, post);
        return post;
    }
};