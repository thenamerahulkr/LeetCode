class Solution {
public:
    bool checkPowersOfThree(int n) {
        // while(n){
        //     int rem = n % 3;
        //     if(rem == 2) return false;
        //     n = n/3;
        // }
        // return true;
        if(n == 0) return true;
        if(n % 3 ==2) return false;
        return checkPowersOfThree(n/3);
    }
};