class Solution {
public:
    int total_days(vector<int>& weights, int capacity){
        int load = 0;
        int total_days = 1;
        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > capacity){
                total_days += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return total_days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        int ans = low;
        while(low <= high){
            int mid = low + (high - low)/2;
            int req_days = total_days(weights, mid);
            if(req_days <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};