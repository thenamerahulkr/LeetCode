class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        // if (!root) return true;
        int val = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val != val) return false;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return true;
    }
};