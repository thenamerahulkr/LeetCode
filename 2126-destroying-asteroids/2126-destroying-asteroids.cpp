class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long m = mass;
        // sort(asteroids.begin(), asteroids.end());
        // for(int i = 0; i < n; i++){
        //     if(m <= 0) return false;
        //     long long asteroid = asteroids[i];
        //     if(m >= asteroid){
        //         m = m + asteroid;
        //     }else if(m < asteroid) return false;
        // }
        // return true;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto &asteroid : asteroids) {
            pq.push(asteroid);
        }
        while (!pq.empty()) {
            long long asteroid = pq.top();
            pq.pop();

            if (m >= asteroid) {
                m = m + asteroid;
            } else if (m < asteroid)
                return false;
        }
        return true;
    }
};