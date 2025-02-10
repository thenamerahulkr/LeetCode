class Solution {
public:
    string clearDigits(string s) {
        stack <char> st;
        string sh ="";
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(isalpha(ch)){
                st.push(ch);
            }
            if(isdigit((ch)) and st.size()>0){
                st.pop();
            }
        }
        while(st.size()>0){
            sh=st.top()+sh;
            st.pop();
        }
        return sh;
    }
};