class Solution {
public:
    void solve(int n, string& temp, char prev, vector<string>& ans) {
        // base case
        if (n == 0) {
            ans.push_back(temp);
            return;
        }
        // we have two option either we take zero or one but if prev element is
        // zero we cannot take
        if (prev != '0') {
            temp += '0';
            solve(n - 1, temp, '0', ans);
            temp.pop_back();
            
             // take 1
            temp += '1';
            solve(n - 1, temp, '1', ans);
            temp.pop_back();
            
        } else {
            temp += '1';
            solve(n - 1, temp, '1', ans);
            temp.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp = "";
        solve(n, temp, '1', ans);
        return ans;
    }
};