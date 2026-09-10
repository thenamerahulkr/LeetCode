class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int ansLevel = 1;
        int maxSum = INT_MIN;
        while (!q.empty()) {
            int size = q.size();
            int currentSum = 0;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                currentSum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            // Current level ka sum check
            if (currentSum > maxSum) {
                maxSum = currentSum;
                ansLevel = level;
            }
            level++;
        }
        return ansLevel;
    }
};