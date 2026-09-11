class Solution {
public:
    bool usingDfs(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p && q)
            return false;
        if (p && !q)
            return false;
        if (p->val != q->val)
            return false;
        return usingDfs(p->left, q->left) && usingDfs(p->right, q->right);
    }
    bool usingBfs(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> Q;
        Q.push(p);
        Q.push(q);
        while (!Q.empty()) {
            TreeNode* node1 = Q.front();
            Q.pop();
            TreeNode* node2 = Q.front();
            Q.pop();
            if (!node1 && !node2) continue;
            if (!node1 || !node2)
                return false;
            if (node1->val != node2->val)
                return false;
            Q.push(node1->left);
            Q.push(node2->left);
            Q.push(node1->right);
            Q.push(node2->right);
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // return usingDfs(p, q);
        return usingBfs(p, q);
    }
};