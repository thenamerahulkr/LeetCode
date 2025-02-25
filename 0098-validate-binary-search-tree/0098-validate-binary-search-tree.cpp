class Solution {
public:
    // void inorderTraversal(TreeNode* root, vector<int> &in) {
    //     stack<TreeNode*> st;
    //     TreeNode *node = root;
    //     while(st.size()>0 or node){
    //         if(node){
    //             st.push(node);
    //             node = node->left;
    //         }
    //         else{
    //             TreeNode *temp = st.top();
    //             st.pop();
    //             in.push_back(temp->val);
    //             node = temp->right;
    //         }
    //     }
    // }
    long long mini(TreeNode* root){
        if(root== nullptr) return LLONG_MAX;
        return min((long long)root->val,min(mini(root->left), mini(root->right)));
    }
    long long maxi(TreeNode* root){
        if(root== nullptr) return LLONG_MIN;
        return max((long long)root->val,max(maxi(root->left), maxi(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        // vector<int> in;
        // inorderTraversal(root,in);
        // for(int i =1;i<in.size(); i++){
        //     if(in[i]<=in[i-1]) return false;
        // }
       if(!root) return true;
       if (root->val > maxi(root->left) and root->val < mini(root->right)){
         return isValidBST(root->left) and isValidBST(root->right);
       }
       else return false;
      

    }
};