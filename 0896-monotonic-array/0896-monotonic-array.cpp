class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true;
        bool dec=true;
        for(int i=1;i<nums.size();i++){
            // inc
            if(nums[i]<nums[i-1]){
                inc=false;
            }
            else if(nums[i]>nums[i-1]){
                dec=false;
            }
            if(!inc&&!dec){
                break;
            }
        }
        return inc||dec;
    }
};