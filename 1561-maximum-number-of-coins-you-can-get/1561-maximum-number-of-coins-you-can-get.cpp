class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int max_coin = 0;
        int left_tak = piles.size()/3;
        sort(piles.begin(), piles.end());
        for(int i = piles.size()-2; i >= left_tak; i -= 2){
            max_coin = piles[i] + max_coin;
        }
        return max_coin;
    }
};