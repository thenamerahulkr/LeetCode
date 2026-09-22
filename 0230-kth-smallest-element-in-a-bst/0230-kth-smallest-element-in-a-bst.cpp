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
    int solvedfs(TreeNode* root, int& counter, int k) {
        if (!root)
            return -1;
        int left = solvedfs(root->left, counter, k);
        if (left != -1)
            return left;
        counter++;
        if (counter == k)
            return root->val;
        return solvedfs(root->right, counter, k);
    }
    int kthSmallest(TreeNode* root, int k) { 
        int counter = 0;
        return solvedfs(root, counter, k); }
};