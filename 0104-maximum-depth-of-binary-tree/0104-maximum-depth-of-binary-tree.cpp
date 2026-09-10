class Solution {
public:
    int usingRecursion(TreeNode* root){
        if (!root) return 0;
        return 1 + max(usingRecursion(root->left), usingRecursion(root->right));
    }
    int usingLevelOrder(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        if(!root) return height;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* currentNode = q.front();
                q.pop();
                if(currentNode->left) q.push(currentNode->left);
                if(currentNode->right) q.push(currentNode->right);
            }
            height++;
        }
        return height;
    }
    int maxDepth(TreeNode* root) {
        // return usingRecursion(root); 
        return usingLevelOrder(root);
    }
};