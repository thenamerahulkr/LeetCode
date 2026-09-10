class Solution {
public:
    void leverOrderTraversal(TreeNode* root, vector<vector<int>>& levelOrder) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> singleLevel;
            while (size--) {
                TreeNode* current = q.front();
                q.pop();
                singleLevel.push_back(current->val);
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            levelOrder.push_back(singleLevel);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        // if (!root->left && !root->right)
        //     return root->val;
        vector<vector<int>> levelOrder;
        leverOrderTraversal(root, levelOrder);
        return levelOrder;
    }
};