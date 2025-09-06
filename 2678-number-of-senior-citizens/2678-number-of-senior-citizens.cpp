class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int result=0;
        for (int i = 0; i < n; i++) {
            string str = details[i];
            int tens = str[11] - '0';
int ones = str[12] - '0';
int age = tens * 10 + ones;
if (age > 60) result++;
        }
        
        return result;
    }
};