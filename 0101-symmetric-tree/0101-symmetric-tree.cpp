class Solution {
public:
    bool usingDfs(TreeNode* left, TreeNode* right){
        if (!left && !right) return true;
        if (!left || !right) return false;
        if(left->val != right->val) return false;
        return usingDfs(left->left, right->right) && usingDfs(left->right, right->left);
    }
    bool usingBfs(TreeNode* left, TreeNode* right){
        queue<TreeNode*> q;
        q.push(left);
        q.push(right);
        
        while (!q.empty()) {
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();
            if (!t1 && !t2) continue;
            if (!t1 || !t2) return false;
            if (t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return usingBfs(root->left, root->right);
    }
};