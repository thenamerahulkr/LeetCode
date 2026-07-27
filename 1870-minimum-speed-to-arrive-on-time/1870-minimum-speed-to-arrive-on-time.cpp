class Solution {
private:
    bool is_possible(vector<int>& dist, double hour, int mid){
        int n = dist.size();
        double currSum = 0;
        for(int i = 0; i < n - 1; i++){
           currSum += ceil((double)dist[i] / mid);
        }
        currSum += (double)dist[n - 1] / mid;
        return currSum  <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int minimun_time = -1;
        int low = 1;
        // int high = *max_element(dist.begin(), dist.end());
        int high = 1e7;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(is_possible(dist, hour, mid)){
                minimun_time = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return minimun_time;
    }
};