class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> bottomUpLevelorder;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            bottomUpLevelorder.push_back(currentLevel);
        }
        // Reverse the levels
        reverse(bottomUpLevelorder.begin(), bottomUpLevelorder.end());
        return bottomUpLevelorder;
    }
};