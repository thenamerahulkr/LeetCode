class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans(gain.size()+1,0);
        for(int i=0;i<gain.size();i++){
            ans[i+1]=gain[i]+ans[i];
        }
        return *max_element(ans.begin(),ans.end());
    }
};