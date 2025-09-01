class Solution {
    void BFS(TreeNode* root, vector<long long>& v) {

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            long long sum = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            v.push_back(sum);
        }
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> v;
        BFS(root, v);
        sort(v.begin(), v.end());
        int n = v.size();
        // for (int i = 1; i <= n; i++) {
        //     if (i == k)
        //         return v[i];
        // }
        if(k <= n) return v[n-k];
        else return -1;
    }
};