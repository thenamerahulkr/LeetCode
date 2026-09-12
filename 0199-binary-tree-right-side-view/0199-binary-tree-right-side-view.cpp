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
    void levelOrderTraversalFromRight(TreeNode* root, vector<int>& rightView){
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* current = q.front();
                q.pop();
                if(flag){
                    rightView.push_back(current->val);
                    flag = false;
                }
                if(current->right) q.push(current->right);
                if(current->left) q.push(current->left);
            }
            flag = true;
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> rightView;
        levelOrderTraversalFromRight(root, rightView);
        return rightView;
    }
};