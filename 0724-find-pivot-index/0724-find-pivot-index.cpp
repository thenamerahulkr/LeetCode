class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        int n=nums.size();
        left[0]=0;
        right[n-1]=0;
        for(int i =1;i<nums.size();i++){
            left[i]=nums[i-1]+left[i-1];
        }
        for(int j=nums.size()-2;j>=0;j--){
            right[j]=nums[j+1]+right[j+1];
        }
        for(int i =0;i<nums.size();i++){
            if(left[i]==right[i]){
                return i;
            }
        }
        return -1;
    }
};