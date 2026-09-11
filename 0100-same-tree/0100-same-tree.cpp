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
    bool usingDfs(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p && q)
            return false;
        if (p && !q)
            return false;
        if(p->val != q->val) return false;
        return usingDfs(p->left, q->left) && usingDfs(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) { return usingDfs(p, q); }
};