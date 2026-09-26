class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }
        string result = "";
        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                string key = "";
                i++;
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                if (mp.find(key) != mp.end()) {
                    result += mp[key];
                } else {
                    result += "?";
                }
                i++; 
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};