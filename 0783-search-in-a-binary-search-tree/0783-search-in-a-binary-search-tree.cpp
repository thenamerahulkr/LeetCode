/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* search(TreeNode* root, int val){
        // base case 
        if(!root) return nullptr;

        if(root->val == val) return root;
        else if(root->val > val) return search(root->left, val);
        else  return search(root->right, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root, val);
    }
};