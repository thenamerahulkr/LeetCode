class Solution {
private:
    void solve(string digits, int index, string current, vector<string>& result, const vector<string>& mapping) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        string letters = mapping[digit];
        
        for (char c : letters) {
            solve(digits, index + 1, current + c, result, mapping);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        const vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        solve(digits, 0, "", result, mapping);
        return result;
    }
};