class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = count(s.begin(),s.end(),letter);
        if(cnt==0){
            return 0;
        }
        return (cnt*100)/s.length();
    }
};