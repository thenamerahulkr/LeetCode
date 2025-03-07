class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(auto i: candyType){
            st.insert(i);
        }
        int no_of_candies = candyType.size()/2;
        int ans = min(no_of_candies, (int)st.size());
        return ans;
    }
};