class Solution {
public:
    bool check(string& binaryStr){
        int left = 0;
        int right = binaryStr.length() - 1;

        while (left < right) {
            if (binaryStr[left] != binaryStr[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string fullBinary = "";
        for (char& ch : s) {
            fullBinary += bitset<8>(ch).to_string();
        }
        return check(fullBinary);
    }
};