/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; // ture matlab ki normal order me fill karo
        while(q.size()>0){
            int level = q.size();
            vector<int> v(level);
            for(int i=0; i<level; i++){
                TreeNode* temp = q.front();
                q.pop();
                int index = (flag)? i : (level-1-i);
                v[index] = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(v);
            flag =!flag;
        }
        return ans;
    }
};