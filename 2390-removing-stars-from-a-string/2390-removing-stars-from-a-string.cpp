class Solution {
public:
    string removeStars(string s) {
        string str = "";
        int n = s.length();
        stack<char> st;
        for(int i = 0; i<n;i++){
           

            if(!st.empty() and s[i] == '*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            
        }
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};