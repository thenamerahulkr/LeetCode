class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

    int numBars = 0;
    
    // Iterate through the sorted prices and buy as many as we can
    for (int i = 0; i < costs.size(); ++i) {
        if (coins >= costs[i]) {
            coins -= costs[i];  // Deduct the price of the bar from the coins
            numBars++;          // Increase the count of bars purchased
        } else {
            break;  // Stop if we don't have enough coins for the next ice cream
        }
    }
    
    return numBars;
    }
};