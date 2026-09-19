class Solution {
public:
    int getnodesLeft(TreeNode* root){
        int left = 0;
        TreeNode* temp = root;
        while(temp){    
            left++;
            temp = temp->left;
        }
        return left;
    }
    int getnodesRight(TreeNode* root){
        int right = 0;
        TreeNode* temp = root;
        while(temp){    
            right++;
            temp = temp->right;
        }
        return right;
    }
    int powerOfTwo(int lh){
        if (lh == 0) return 1;
        return 2 * powerOfTwo(lh - 1);
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = getnodesLeft(root);
        int rh = getnodesRight(root);
        if(lh == rh) return powerOfTwo(lh) - 1;
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};
