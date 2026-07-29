class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int max_vowels = 0;
        int count = 0;
        // pehle k length tk kr dete h isko 
        for(right = 0; right < k; right++){
            char ch = s[right];
            if(isVowel(ch)) count ++;
        }
        max_vowels = max(count, max_vowels);

        while(right < n){
            if (isVowel(s[left])) {
                count--;
            }
            if (isVowel(s[right])) {
                count++;
            }
            max_vowels = max(max_vowels, count);
            right++;
            left++;
        }
        return max_vowels;
    }
};