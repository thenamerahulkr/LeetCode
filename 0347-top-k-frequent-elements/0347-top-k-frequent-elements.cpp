class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // freq , ele
        unordered_map<int, int> freq_map;
        for(auto& num : nums){
            freq_map[num]++;
        }

        priority_queue<p, vector<p>, greater<p>> pq;

        for(auto& [ele,freq] : freq_map){
            pq.push({freq,ele});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};