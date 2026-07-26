class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // c < a + b
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        // long long perimeter = -1;
        // long long cumm = nums[0] + nums[1];
        // for(int i = 2; i < n; i++){
        //     if(nums[i] >= cumm) cumm = cumm + nums[i];
        //     else{
        //         cumm += nums[i];
        //         perimeter = max(cumm, perimeter);
        //     }
        // }

        // return perimeter;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        long long perimeter = -1;
        long long cumm = pq.top();
        pq.pop();
        cumm += pq.top();
        pq.pop();
        while(!pq.empty()){
            int number = pq.top();
            pq.pop();
            if(number >= cumm) cumm += number;
            else{
                cumm += number;
                perimeter = max(cumm, perimeter);
            }
        }
        return perimeter;
    }
};