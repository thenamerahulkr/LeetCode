class Solution {
public:
    void postorder(TreeNode*&root, vector<int>&post){
        if(root==NULL){
           return;
        }
        postorder(root->left,post);
        postorder(root->right,post);
        post.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        postorder(root,post);
        return post;
    }
};