class Solution {
public:
    bool preOrderTraversal(TreeNode* root, int uniValue){
        if(!root) return true;
        if(root->val != uniValue) return false;
        bool leftResult = preOrderTraversal(root->left, uniValue);
        bool rightResult = preOrderTraversal(root->right, uniValue);
        return leftResult && rightResult;
    }
    bool isUnivalTree(TreeNode* root) {
        // stack<TreeNode*> st;
        // st.push(root);
        int val = root->val;
        // while(st.size()>0){
        //     TreeNode* temp = st.top();
        //     st.pop();
        //     if(temp->val != val) return false;
        //     if(temp->right) st.push(temp->right);
        //     if(temp->left) st.push(temp->left);
        // }
        // return true;
        return preOrderTraversal(root, val);
    }
};