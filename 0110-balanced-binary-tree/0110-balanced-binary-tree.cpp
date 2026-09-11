class Solution {
public:
    int heightUsingLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        if (!root)
            return height;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* currentNode = q.front();
                q.pop();
                if (currentNode->left)
                    q.push(currentNode->left);
                if (currentNode->right)
                    q.push(currentNode->right);
            }
            height++;
        }
        return height;
    }
    int heightUsingRecursion(TreeNode* root){
        if(!root) return 0;
        return 1 + max(heightUsingRecursion(root->left), heightUsingRecursion(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int leftHeight = heightUsingRecursion(root->left);
        int rightHeight = heightUsingRecursion(root->right);
        if(abs(leftHeight - rightHeight)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};