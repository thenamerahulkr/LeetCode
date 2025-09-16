class Solution {
public:
    
    string kthLargestNumber(vector<string>& nums, int k) {
        auto lessNum = [](const string& a, const string& b) {
            if (a.size() != b.size()) return a.size() < b.size(); // a smaller -> true
            return a < b;                                         // a smaller -> true
        };
        priority_queue<string, vector<string>, decltype(lessNum)> pq(lessNum);
        for(auto  s : nums){
            pq.push(s);
        }
        while(k > 1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};