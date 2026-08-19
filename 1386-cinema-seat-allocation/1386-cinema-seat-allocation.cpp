class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> reservedMap;

        for (const auto& seat : reservedSeats) {
            reservedMap[seat[0]].insert(seat[1]);
        }

        int totalGroups = (n - reservedMap.size()) * 2;

        for (const auto& [row, seats] : reservedMap) {
            bool leftBlocked = seats.count(2) || seats.count(3) || seats.count(4) || seats.count(5);
            bool rightBlocked = seats.count(6) || seats.count(7) || seats.count(8) || seats.count(9);
            bool middleBlocked = seats.count(4) || seats.count(5) || seats.count(6) || seats.count(7);

            if (!leftBlocked && !rightBlocked) {
                totalGroups += 2;
            } else if (!leftBlocked || !rightBlocked || !middleBlocked) {
                totalGroups += 1;
            }
        }

        return totalGroups;
    }
};