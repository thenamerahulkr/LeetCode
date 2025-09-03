class Solution {
public:
    // inc
    // bool helper2(vector<int>& v) {
    //     int n = v.size();
    //     for (int i = 1; i < n; i++) {
    //         if (v[i] <= v[i - 1])
    //             return false;
    //     }
    //     return true;
    // }
    // // dec
    // bool helper1(vector<int>& v) {
    //     int n = v.size();
    //     for (int i = 1; i < n; i++) {
    //         if (v[i] >= v[i - 1])
    //             return false;
    //     }
    //     return true;
    // }

    bool BFS(TreeNode* root) {
        // int prev = -1;
        queue<TreeNode*> q;
        q.push(root);
        bool level = true; // true mean even
        while (q.size() > 0) {
            int n = q.size();
            // vector<int> v;
            int prev = level ? INT_MIN : INT_MAX;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                int x = temp->val;
                if (level) { 
                    if (x % 2 == 0)
                        return false; 
                    if (x <= prev)
                        return false; 
                } else {             
                    if (x % 2 != 0)
                        return false; 
                    if (x >= prev)
                        return false;
                }
                prev = x;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            // bool result = false;
            // if(level) result = helper2(v);
            // if(!level) result = helper1(v);
            // if(!result) return false;
            level = !level;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) { return BFS(root); }
};