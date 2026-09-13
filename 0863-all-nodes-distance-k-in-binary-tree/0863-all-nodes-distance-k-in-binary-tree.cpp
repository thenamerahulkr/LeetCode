class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> visited;
    void fillParent(TreeNode* root){
        if(!root) return;
        if(root->left){
            parent[root->left] = root;
            fillParent(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            fillParent(root->right);
        }
    }
    void levelOrderTraversal(TreeNode* root, vector<int>& allNodesAtK, int k){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        visited.insert(root);
        int currentLevel = 0;
        while(!q.empty()){
            int size = q.size();
            if (currentLevel == k) {
                while (!q.empty()) {
                    allNodesAtK.push_back(q.front()->val);
                    q.pop();
                }
                return;
            }
            while(size--){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited.count(current->left)){
                    visited.insert(current->left);
                    q.push(current->left);
                }
                if(current->right && !visited.count(current->right)){
                    visited.insert(current->right);
                    q.push(current->right);
                }
                if(parent.find(current) != parent.end() && parent[current] != nullptr && !visited.count(parent[current])){
                    visited.insert(parent[current]);
                    q.push(parent[current]);
                }
            }
            currentLevel++;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> allNodesAtK;
        if (!root || !target) return allNodesAtK;
        parent[root] = nullptr;
        fillParent(root);
        levelOrderTraversal(target, allNodesAtK, k);
        return allNodesAtK;
    }
};