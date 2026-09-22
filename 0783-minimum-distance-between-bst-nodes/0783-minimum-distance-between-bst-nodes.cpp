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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        
        int minDiff = INT_MAX;
        for (size_t i = 1; i < arr.size(); ++i) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }
        
        return minDiff;
    }
};