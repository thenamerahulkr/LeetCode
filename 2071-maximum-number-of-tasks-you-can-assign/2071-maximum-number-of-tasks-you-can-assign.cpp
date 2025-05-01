class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers(workers.end() - k, workers.end());
        
        for (int i = k - 1; i >= 0; --i) {
            int task = tasks[i];
            auto it = availableWorkers.lower_bound(task);
            if (it != availableWorkers.end()) {
                availableWorkers.erase(it); // assign directly
            } else {
                if (pills == 0)
                    return false;

                auto it2 = availableWorkers.lower_bound(task - strength);
                if (it2 == availableWorkers.end())
                    return false;

                availableWorkers.erase(it2); // give pill
                pills--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min((int)tasks.size(), (int)workers.size());
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
