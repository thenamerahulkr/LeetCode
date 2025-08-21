class Solution {
public:
    int solve(int a, int b, string token){
        if(token == "+") return a+b;
        if(token == "-") return b-a;
        if(token == "*") return a*b;
        if(token == "/") return b/a;
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int result = solve(a, b, tokens[i]);
                st.push(result);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};