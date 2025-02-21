class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        if (root == nullptr)
            return post;
        // stack <TreeNode*> st;
        // st.push(root);
        // while(st.size()>0){
        //     TreeNode* temp = st.top();
        //     st.pop();
        //     post.push_back(temp->val);
        //     if(temp->left) st.push(temp->left);
        //     if(temp->right) st.push(temp->right);
        // }
        // reverse(post.begin(), post.end()); if (root == nullptr) return;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            TreeNode* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }

        while (!s2.empty()) {
            post.push_back(s2.top()->val);
            s2.pop();
        }
        return post;
    }
};