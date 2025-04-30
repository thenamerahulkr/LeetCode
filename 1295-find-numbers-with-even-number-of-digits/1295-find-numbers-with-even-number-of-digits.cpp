class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int & it :nums){
            int num = it;
            string str = to_string(num);
            if(str.length() %2 ==0){
                count++;
            }
        }
        return count;
    }
};