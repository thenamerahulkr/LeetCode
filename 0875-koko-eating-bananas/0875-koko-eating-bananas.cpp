class Solution {
private:
    bool kya_kha_payega(int mid, int h, vector<int> &piles){
        int n = piles.size();
        int total_hours = 0;
        for(auto &pile : piles){
            total_hours += (pile + mid - 1) / mid;
        }
        if(total_hours <= h) return true;
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        // binary search lgao ab
        int answer = INT_MAX;
        while(low <= high){
            // high - low / 2 
            int mid = high - (high - low)/ 2;
            if(kya_kha_payega(mid, h, piles)){
                answer = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return answer;
    }
};