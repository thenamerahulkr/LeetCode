class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0, max_length = 0;
        unordered_map<int, int> fruits_count;
        while(right < fruits.size()){
            fruits_count[fruits[right]]++;
            if(fruits_count.size() > 2){
                fruits_count[fruits[left]]--;
                if(fruits_count[fruits[left]] == 0) fruits_count.erase(fruits[left]);
                left++;
            }
            if(fruits_count.size() <= 2){
                max_length = max(max_length, right - left + 1);
            }
            right++;
        }
        return max_length;
    }
};