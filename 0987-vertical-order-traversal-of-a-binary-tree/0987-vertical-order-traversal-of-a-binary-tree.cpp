/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(0), right(0) {}
 *     TreeNode(int x) : val(x), left(x), right(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes grouped by column -> row -> multiset of values
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue for BFS: stores pairs of (node, {row, col})
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int row = p.second.first;
            int col = p.second.second;
            
            nodes[col][row].insert(node->val);
            
            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto& [col, rowMap] : nodes) {
            vector<int> colList;
            for (auto& [row, st] : rowMap) {
                colList.insert(colList.end(), st.begin(), st.end());
            }
            result.push_back(colList);
        }
        
        return result;
    }
};