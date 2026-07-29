class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,
                    int additionalRocks) {
        int n = rocks.size();
        vector<int> diff;

        for (int i = 0; i < capacity.size(); i++) {
            diff.push_back(abs(capacity[i] - rocks[i]));
        }
        int count = 0;
        sort(diff.begin(), diff.end());
        for(int i = 0; i < n; i++){
            if(diff[i] <= additionalRocks){
                additionalRocks -= diff[i];
                count++;
            }
            if(additionalRocks <= 0) break;
        }
        return count;
    }
};