class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            if (ch == '(') {
                st.push(ch);
            } else {
                if (st.empty())
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
    void solve(vector<string>& ans, string& temp, int n){
        // base case 
        if(temp.size() == 2 * n){
            if(isValid(temp)){
                ans.push_back(temp);
               
            }
             return;
        }
        temp.push_back(')');
        solve(ans, temp, n);
        temp.pop_back();
        
        temp.push_back('(');
        solve(ans, temp, n);
        temp.pop_back(); 
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(ans,temp,n);
        return ans;
    }
};