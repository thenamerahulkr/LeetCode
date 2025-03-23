class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int maxPossible = n * n;  // Maximum containers the deck can hold
        int weightLimit = maxWeight / w;  // Maximum containers based on weight constraint
        return min(maxPossible, weightLimit);
    }
};