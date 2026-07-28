class Solution {
public:
    int count_greater_bs(int spell, vector<int>& potions, long long success) {
        // mujhe khojna h ki wo index jiska prod with spell succes ke barabar ho
        // ya usse jada
        int n = potions.size();
        int low = 0;
        int high = n - 1;
        int index = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long prod = (long long)spell * (long long)potions[mid];
            if (prod >= success) {
                index = mid;    // Valid index mila, par chalo left me aur check
                                // karte hain
                high = mid - 1; // Search in left half for smaller index
            } else {
                low = mid + 1; // Product chota hai, right side me jao
            }
        }
        return (index == -1) ? 0 : (n - index);
    }
    int count_greater(int spell, vector<int>& potions, long long success) {
        int count = 0;
        for (int i = 0; i < potions.size(); i++) {
            long long prod = spell * (long long)potions[i];
            if (prod < success)
                continue;
            else if (prod >= success) {
                count = potions.size() - i;
                break;
            }
        }
        return count;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size();
        vector<int> answer(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++) {
            int spell = spells[i];
            // function jo count btayega kitne greater hai and uss count ko
            // store kr denge answer me
            answer[i] = count_greater_bs(spell, potions, success);
        }
        return answer;
    }
};