class Solution {

public:
    
    void target_hai(TreeNode* root, int sum, int targetSum,
                    vector<vector<int>>& ans, vector<int>& temp) {
        // base condition
       
        if (root == nullptr) {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if ((sum == targetSum) and
            (root->left == nullptr and root->right == nullptr)) {
            ans.push_back(temp);
        }

        target_hai(root->left, sum, targetSum, ans, temp);
        target_hai(root->right, sum, targetSum, ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;
        target_hai(root, 0, targetSum, ans, temp);
        return ans;
    }
};