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
    void inorderTraversal(TreeNode* root, int &sum) {
        if (root == nullptr)
            return;
        inorderTraversal(root->right,sum); // Visit right subtree
        sum=sum+root->val;
        root->val=sum;
        inorderTraversal(root->left,sum);  // Visit left subtree
    }
    TreeNode* bstToGst(TreeNode* root) {
      int sum=0;
      inorderTraversal(root,sum);
      return root;
    }
};