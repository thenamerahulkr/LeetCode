class Solution {
public:
    bool isPalindrome(int x) {
        int k=x;
        long reverse=0;
        while(k>0){
            int last = k%10;
            k=k/10;
            reverse=(reverse*10)+last;
        }
        if(reverse==x) return true;
        else return false;
    }
};