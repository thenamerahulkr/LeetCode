class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        // stack<char> st;
        int count=0;
        int max_count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                count--;
            }
            max_count=max(count,max_count);
        }

        return max_count;
    }
};