class Solution {
public:
    int find_digit_sum(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num = num/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int , int> mp;
        int max_size = 0;
        int count = 0;
        for(int i = 1; i<=n; i++){
            int sum_of_digit = find_digit_sum(i);
            mp[sum_of_digit]++;
            if(mp[sum_of_digit] == max_size){
                count++;
            }
            else if(mp[sum_of_digit] > max_size){
                max_size = max(max_size,mp[sum_of_digit]);
                count = 1;
            }
        }
        return count;
    }
};