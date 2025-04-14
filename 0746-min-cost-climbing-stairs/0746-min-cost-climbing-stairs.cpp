class Solution {
    vector<int> dp;
private:
    int min_cost(vector<int>& cost, int i){
        // base case 
        if(i > cost.size()-1) return 0;
        id(dp[i] != -1) return dp[i];
        // jump 1 step 
        int one_step = cost[i] + min_cost(cost,i+1);
        //jump 2 step 
        int two_step = cost[i] + min_cost(cost, i+2);
        dp[i] = min(one_step, two_step);
        return dp[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        dp.clear();
        dp.resize(cost.size()+1,-1);
        int cost1 = min_cost(cost,0);
        dp.clear();
        dp.resize(cost.size()+1,-1);
        int cost2 = min_cost(cost,1);
        return min(cost1,cost2);
    }
};