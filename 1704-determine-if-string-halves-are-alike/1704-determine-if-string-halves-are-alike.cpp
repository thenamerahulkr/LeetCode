class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int vowels = 0;
        
        for (int i = 0; i < n / 2; ++i) {
            if (isVowel(s[i])) vowels++;
        }
        
        for (int i = n / 2; i < n; ++i) {
            if (isVowel(s[i])) vowels--;
        }
        
        return vowels == 0;
    }
};