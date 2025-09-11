class Solution {
public:
    int bada_number = 1e9;
    int solve(vector<int>& coins, int amount, int index){
        if(index >= coins.size()) return bada_number;
        if(amount == 0) return 0;
        if(amount < 0) return bada_number;
        int take = 1 + solve(coins, amount - coins[index], index);
        int not_take = solve(coins, amount, index + 1);
        return min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins,amount,0);
        return ans >= bada_number ? -1 : ans;
    }
};