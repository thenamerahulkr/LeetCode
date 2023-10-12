class Solution {
public:
    bool rotateString(string s,string goal){
        if(s.size()!=goal.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            s=s.substr(1,s.size())+s.substr(0,1);
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};