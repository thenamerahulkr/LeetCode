class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(strs.size()==1) return strs[0];
        string str = "";
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[n-1];
        for(int i=0;i<(min(first.size(),last.size()));i++){
            if(first[i]==last[i]){
                str = str+first[i];
            }
            else return str;
        }
        return str;
    }
};