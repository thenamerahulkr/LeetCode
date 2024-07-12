class Solution {
public:
    string finalString(string s) {
        string result="";
        for(auto i:s){
            if(i=='i'){
                reverse(result.begin(),result.end());
            }
            else{
                result+=i;
            }
        }
        return result;
    }
};