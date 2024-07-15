class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for(int i = left ; i <= right; i++ ){
            char fnt = words[i].front();
            char bck = words[i].back();
            if((fnt=='a' or fnt=='e' or fnt=='i' or fnt=='o' or fnt=='u')and(bck=='a' or bck=='e' or bck=='i' or bck=='o' or bck=='u')){
                cnt++;
            }
        }
    return cnt;
      }  
};