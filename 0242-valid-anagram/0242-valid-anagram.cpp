class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false; 
    map<char, int> freq1, freq2;
    for (char ch : s) freq1[ch]++; 
    for (char ch : t) freq2[ch]++;
    return freq1 == freq2;
    }
};