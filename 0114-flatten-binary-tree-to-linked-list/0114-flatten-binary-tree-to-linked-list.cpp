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
    void preOrder(TreeNode* root, vector<TreeNode*> &vec){
        if(!root) return;
        vec.push_back(root);
        preOrder(root->left,vec);
        preOrder(root->right,vec);
    }
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> vec;
        preOrder(root,vec);
        for(int i =0;i<vec.size()-1;i++){
            vec[i]->right = vec[i+1];
            vec[i]->left = nullptr;
        }
        vec[vec.size()-1]->left = nullptr;
        vec[vec.size()-1]->right = nullptr;

    }
};