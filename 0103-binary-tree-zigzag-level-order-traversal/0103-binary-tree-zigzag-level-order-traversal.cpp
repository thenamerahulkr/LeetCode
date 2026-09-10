class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigZagLevelOrder;
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; //-> true mean normal way and false mean opposite way!
        while (!q.empty()) {
            int size = q.size();
            int s = q.size();
            vector<int> currentLevel(size);
            int i = 0;
            while(size--) {
                TreeNode* currentNode = q.front();
                q.pop();
                int index = (flag) ? i : (s - 1 - i);
                currentLevel[index] = currentNode->val;
                i++;
                if (currentNode->left)
                    q.push(currentNode->left);
                if (currentNode->right)
                    q.push(currentNode->right);
            }
            zigZagLevelOrder.push_back(currentLevel);
            flag = !flag;
        }
        return zigZagLevelOrder;
    }
};