class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = "1";
        for (int i = 2; i <= n; i++) {
            const int len = s.size(); 
            string t; 
            t.reserve(len << 1); 
            for (int j = 0; j < len;) {
                char c = s[j]; 
                int count = 1; 
                while (j + count < len && s[j + count] == c) count++;
                t.push_back('0' + count); 
                t.push_back(c);
                j += count;
            }
            s = move(t);
        }  
        return s;
    }
};