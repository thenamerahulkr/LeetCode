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
    int inorderTraversal(TreeNode* root, int low , int high) {
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while (st.size() > 0 or node) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                TreeNode* temp = st.top();
                st.pop();
                if(temp->val >=low and temp->val <= high){
                    sum+=temp->val;
                }
                node = temp->right;
            }
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return inorderTraversal(root,low,high);
    }
};