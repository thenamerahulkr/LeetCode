class Solution {
public:
    bool is_this_force_possible(vector<int>& position, int mid, int m){
        int n = position.size();
        // yha m is the number of balls hai 
        // and mid jo hai wo force hai ki ye possible hai ya ni 
        int i = 0;
        int j = 0;
        // mujhe khojna hai m - 1 baar mid diff 
        int count = 1;
        while(j < n){
            if(abs(position[i] - position[j]) >= mid){
                i = j; 
                count++;
            }
            j++;
        }
        return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        // yha minimum force toh 1 hga hi hoga right 
        // -> maximum force -> if we place ball on position 1st and last in sorted array if we have two balls  -> max - min = 7 - 1 = 6; we can 7 also its ok
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1;
        int high = position[n-1];
        int max_force = low;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // yha mid kya hai -> kya mid force possible hai ?
            if(is_this_force_possible(position,mid, m)){
                max_force = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return max_force;
    }
};