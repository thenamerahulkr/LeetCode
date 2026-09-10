class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int maxWidth = 1;
        deque<pair<TreeNode*, unsigned long long>> q;
        // left child ka index = 2i + 1 and right ka 2i + 2 ;
        q.push_back({root, 0});
        while (!q.empty()) {
            int size = q.size();
            unsigned long long frontIndex = q.front().second;
            unsigned long long backIndex = q.back().second;
            unsigned long long numberOfNodes = backIndex - frontIndex + 1;
            maxWidth = max(maxWidth, (int)numberOfNodes);
            while (size--) {
                auto [currentNode, index] = q.front();
                q.pop_front();
                if (currentNode->left)
                    q.push_back({currentNode->left, 2 * index + 1});
                if (currentNode->right)
                    q.push_back({currentNode->right, 2 * index + 2});
            }
        }
        return maxWidth;
    }
};