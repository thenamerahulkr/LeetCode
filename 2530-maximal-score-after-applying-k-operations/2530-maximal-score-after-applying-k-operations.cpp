class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while(k > 0){
            int x = pq.top();
            pq.pop();
            sum += x;
            x = ceil(x/3.0);
            pq.push(x);
            k--;
        }
        return sum;
    }
};