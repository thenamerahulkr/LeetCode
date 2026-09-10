/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // iterative
    void usingStack(TreeNode* root, vector<int>& pre) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();
            pre.push_back(current->val);
            if (current->right)
                st.push(current->right);
            if (current->left)
                st.push(current->left);
        }
    }
    // recursive O(n)
    void preOrder(TreeNode* root, vector<int>& pre) {
        if (root == nullptr)
            return;
        pre.push_back(root->val);
        if (root->left)
            preOrder(root->left, pre);
        if (root->right)
            preOrder(root->right, pre);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<int> pre;
        usingStack(root, pre);
        return pre;
    }
};