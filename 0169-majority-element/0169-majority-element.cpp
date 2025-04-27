class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority_element = nums[0];
        int counter = 0;
        for(int &it : nums){
            if(counter == 0){
                majority_element = it;
            }
            if(it == majority_element){
                
                counter++;
            }else{
                majority_element = it;
                counter--;
            }
        }
        return majority_element;
    }
};