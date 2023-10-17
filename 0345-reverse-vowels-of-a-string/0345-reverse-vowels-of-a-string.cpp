class Solution {
public:
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        or c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int left=0,right = s.length()-1;
        while(left < right)
        {
            while(left < right && !isVowel(s[left]))
            {
                left++;
            }
            while(right > left && !isVowel(s[right]))
            {
                 right--;
            }
            if(isVowel(s[left]) && isVowel(s[right]))
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            else break;
        }
        return s;
    }
};