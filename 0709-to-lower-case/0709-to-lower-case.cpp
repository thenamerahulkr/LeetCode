class Solution {
public:
    string toLowerCase(string s) {
        int n =s.size();
        for(int i = 0; i<n;i++){
            char ch = s[i];
            int ascii = int(s[i]);
            if(ascii>=65 && ascii<=90){
                ascii=ascii+32;
                s[i]=char(ascii);
            }
        }
        return s;
    }
};