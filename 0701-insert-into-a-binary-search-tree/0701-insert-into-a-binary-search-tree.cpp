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
    TreeNode* usingIterative(TreeNode* root, int val){
        if(root == nullptr){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        TreeNode* curr = root;
        while(true){
            // left me jao
            if (val < curr->val) {
                if (!curr->left) {
                    curr->left = new TreeNode(val); 
                    break; 
                }
                curr = curr->left;
            }
            // right me jao 
            else {
               if (!curr->right) {
                    curr->right = new TreeNode(val); 
                    break; 
                }
                curr = curr->right;
            }
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if(root == nullptr){
        //     TreeNode* temp = new TreeNode(val);
        //     return temp;
        // }
        // if(val > root->val){
        //    root->right = insertIntoBST(root->right, val);
        // }
        // else{
        //   root->left =  insertIntoBST(root->left, val);
        // }
        // return root;
        return usingIterative(root, val);
    }
};