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
    bool BFS(TreeNode* temp, int k, set<int>& st){
        queue<TreeNode*> q;
        q.push(temp);
        
        // st.insert(temp->val);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(st.size() > 0 and st.count(k - curr->val)) return true;
            
            if(curr->left){
                // st.insert(curr->val);
                q.push(curr->left);
            }
            if(curr->right){
                
                q.push(curr->right);
            }
            st.insert(curr->val);
        }
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root->left and !root->right) return false;
        set<int> st;
        return BFS(root, k, st);
    }
};