class Solution {
public:
    int reverse(int x) {
        int  reverse=0;
        while(x!=0){
            int last = x%10;
            x=x/10;
            reverse=(reverse*10)+last;
        }
        if(reverse>INT_MAX || reverse<INT_MIN) return 0;
        else return reverse;
    }
};