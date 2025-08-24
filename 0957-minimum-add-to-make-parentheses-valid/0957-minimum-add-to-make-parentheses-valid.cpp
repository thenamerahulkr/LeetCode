class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char> st;
        int min_req = 0;
        for(char ch : s){
            if(ch == '(') st.push(ch);
            if(st.size() == 0 and ch == ')') min_req++;
            else if(ch == ')') st.pop();
        }
        if(st.size()) min_req += st.size();
        return min_req;
    }
};