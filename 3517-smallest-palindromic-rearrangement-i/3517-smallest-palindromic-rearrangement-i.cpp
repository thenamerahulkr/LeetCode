class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        // // mujhe chahiye lexographically smaller
        // // store count in freq array;
        // int freq[26] = {0};
        // for(int i = 0; i < n; i++){
        //     freq[s[i] - 'a']++;
        // } 
        // // freq array is ready
        // string left = "";
        // string right = "";
        // string middle = "";
        // for(int i = 0; i < 26; i++){
        //     left += string(freq[i] / 2, char('a' + i));
            
        //    if(freq[i] % 2 != 0)  middle = char('a' + i);
            
        // }
        // right = left;
        // reverse(right.begin(), right.end());
        // return left + middle + right;
        string left = "";
        string right = "";
        string middle = "";
        if(n % 2 != 0) middle += s[n/2];
        
        for(int i = 0; i < n / 2; i++){
            left += s[i];
        }
        sort(left.begin(), left.end());
        for(int i = left.length() - 1; i >= 0; i--){
            right += left[i];
        }

        return left + middle + right;
    }
};