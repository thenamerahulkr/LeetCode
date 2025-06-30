class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0, right = 0,count = 0;;
        int hash[3] = {0};
        while(right < n){
            hash[s[right]-'a']++;
            while(hash[0] >=1 and hash[1]>= 1 and hash[2]>=1){
                count += (n-right);
                hash[s[left]-'a']--;
                left++;
            }
            right++;
        }  
        return count;
    }
};