class Solution {
public:
    string makeGood(string s) {
        string str = "";
        str += s[0];
        for (int i = 1; i < s.length(); i++) {
            if(str.length() and abs(str.back() - s[i]) == 32){
                str.pop_back();
                
            }
            else str += s[i];
        }
        // cout<<str;
        return str;
    }
};