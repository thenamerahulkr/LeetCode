class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if(!root) return 0;
        // return 1 + max(maxDepth(root->left), maxDepth(root->right));


        // iterative method 
        // Time Complexity = O(n);
        //SC = O(n);
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        if(!root) return height;
        while(q.size()>0){
            int levelSize = q.size();
            height++;
            for(int i=0; i<levelSize; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return height;
    }
};