class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        // stack<vector<int>> st;
        q.push(root);
        while (!q.empty()) {
            int level = q.size();
            vector<int> v(level);
            for (int i = 0; i < level; i++) {
                TreeNode* curr = q.front();
                q.pop();
                v[i] = curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            // st.push(v);
            ans.insert(ans.begin(),v);
        }
        // while (st.size() > 0) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        return ans;
    }
};