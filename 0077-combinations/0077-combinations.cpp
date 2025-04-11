class Solution {
private:
    void solve(int start , int end ,int k ,vector<int> &ds, vector<vector<int>> &answer){
        // base case
        if(ds.size()==k){
            answer.push_back(ds);
            return;
        }
        for(int i = start; i<=end; i++){
            ds.push_back(i);
            solve(i+1,end,k,ds,answer);
            //backtrack
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> ds;
        solve(1,n,k,ds,answer);
        return answer;
    }
};