class Solution {
public:
    typedef pair<int,int> p;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        priority_queue<p,vector<p>,greater<p>> pq;
        // frequency array
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            int ele = x.first;
            int freq = x.second;
            pair<int,int> p1 ={freq,-ele};
            pq.push(p1);
        }
        vector<int> ans;
        while(pq.size()>0){
            int times = pq.top().first;
            int ele = -(pq.top().second);
            pq.pop();
            for(int i =0;i<times;i++){
                ans.push_back(ele);
            }
        }
        return ans;
    }
};