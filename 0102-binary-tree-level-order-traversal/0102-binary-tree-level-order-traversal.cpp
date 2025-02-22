class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        if(!root) return ans;
        while (q.size()>0) {
            int n = q.size();
            vector<int> levels;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                levels.push_back(temp->val);
                if (temp->left != NULL)  q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);   
            }
            ans.push_back(levels);
        }
        return ans;
    }
};