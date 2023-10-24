class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans="";
        for(int i=0;i<words.size();i++){
            string str1=words[i];
            ans.push_back(str1[0]);
        }
        if(ans==s) return true;
        return false;
    }
};