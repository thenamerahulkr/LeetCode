class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n){
            int rem = n % 3;
            if(rem == 2) return false;
            n = n/3;
        }
        return true;
    }
};