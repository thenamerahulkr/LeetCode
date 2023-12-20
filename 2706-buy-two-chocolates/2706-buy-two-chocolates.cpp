class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int n = prices.size();
        for(int i =0;i<n-1;i++){
            if(prices[i]+prices[i+1]<=money){
                return money-(prices[i]+prices[i+1]);
            }
        }
        return money;
    }
};