class Solution {
public:
    int height(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    int heightUsingLevelOrder(TreeNode* root){
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        while (!q.empty()) {
            int levelSize = q.size(); 
            height++;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = heightUsingLevelOrder(root->left);
        int rightHeight = heightUsingLevelOrder(root->right);
        int diameter = leftHeight + rightHeight;
        int leftdia = diameterOfBinaryTree(root->left);
        int rightdia = diameterOfBinaryTree(root->right);
        return max(diameter, max(leftdia, rightdia));
    }
};